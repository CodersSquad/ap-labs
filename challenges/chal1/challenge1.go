package main

import (
	"fmt"
	"os"
)

func mapToString(input map[int]bool) string {
	result := ""
	for k := range input {
		result = fmt.Sprintf("%v%c", result, k)
	}
	return result
}

func main() {

	maxLenght := 0
	longest := ""
	tmpRealStr := ""
	tmpStr := make(map[int]bool)

	if len(os.Args) < 2 {
		fmt.Println("Input string is required")
		fmt.Println("Usage: ./challenge1 <input>")
		os.Exit(1)
	}

	input := os.Args[1]
	for _, v := range input {
		if _, ok := tmpStr[int(v)]; ok {
			tmpStr = make(map[int]bool)
			fmt.Printf("SubString: %v\n", tmpRealStr)
		}
		tmpStr[int(v)] = true

		tmpRealStr = mapToString(tmpStr)
		if len(tmpRealStr) > maxLenght {
			longest = tmpRealStr
			maxLenght = len(tmpRealStr)
		}

	}

	fmt.Printf("Longest substring: %v, Lenght: %v\n", longest, maxLenght)
}
