package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	if len(os.Args) > 1 {
		var name strings.Builder
		for i := 1; i < len(os.Args); i++ {
			if i != len(os.Args)-1 {
				name.WriteString(os.Args[i] + " ")
			} else {
				name.WriteString(os.Args[i])
			}
		}
		fmt.Printf("Welcome %v to the jungle \n", name.String())
	}else{
		fmt.Println("Error, not enough arguments, try again")
	}
}
