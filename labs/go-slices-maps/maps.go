package main

import (

	"golang.org/x/tour/wc"
	
	"strings"
	
)

func WordCount(s string) map[string]int {

	maps:=make(map[string]int)
	
	string := strings.SplitAfter(s," ")
	
	for i:=0;i<len(string);i++{
	
		maps[strings.Trim(string[i]," ")]+=1
		
	}
	
	return maps
	
}

func main() {

	wc.Test(WordCount)
	
}
