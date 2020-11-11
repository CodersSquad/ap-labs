package main

import (
	"fmt"
	"runtime"
	"time"
)

var memory runtime.MemStats

func pipeline(memoryLimit uint64) {

	runtime.ReadMemStats(&memory)
	channel := make(chan int)
	current := 0
	var memory runtime.MemStats

	defer func() {
		if goroutine := recover(); goroutine != nil {
			fmt.Println("Maximum number of pipeline stages   : ", current)
			startingTime := time.Now()
			for ; current > 0; current-- {
				channel <- current
			}
			fmt.Println("Time to transit trough the pipeline : ", time.Since(startingTime))
		}

	}()

	for {
		go func() {
			current++
			<-channel
		}()
		runtime.ReadMemStats(&memory)
		if memory.TotalAlloc/1024/1024 > memoryLimit {
			panic("Max Memory Reached")
		}
	}
}

func main() {
	pipeline(1024)
}
