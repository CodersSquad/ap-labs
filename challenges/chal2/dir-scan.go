package main

import (
	"fmt"
	"os"
)

// scanDir stands for the directory scanning implementation
func scanDir(dir string) error {
	return nil
}

func main() {

	if len(os.Args) < 2 {
		fmt.Println("Usage: ./dir-scan <directory>")
		os.Exit(1)
	}

	scanDir(os.Args[1])
}
