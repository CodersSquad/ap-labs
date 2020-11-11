// Copyright © 2016 Alan A. A. Donovan & Brian W. Kernighan.
// License: https://creativecommons.org/licenses/by-nc-sa/4.0/

// See page 241.

// Crawl2 crawls web links starting with the command-line arguments.
//
// This version uses a buffered channel as a counting semaphore
// to limit the number of concurrent calls to links.Extract.
//
// Crawl3 adds support for depth limiting.
//
package main

import (
	"fmt"
	"log"
	"os"
	"strconv"

	"gopl.io/ch5/links"
)

type pageInfo struct {
	url   string
	level int
}

//!+sema
// tokens is a counting semaphore used to
// enforce a limit of 20 concurrent requests.
var tokens = make(chan struct{}, 20)

func crawl(page pageInfo, reached bool) []pageInfo {
	found := make([]pageInfo, 0)
	//fmt.Println(page.url)
	if !reached {
		tokens <- struct{}{} // acquire a token
		list, err := links.Extract(page.url)
		if err != nil {
			log.Print(err)
		}
		<-tokens // release the token
		for _, urls := range list {
			found = append(found, pageInfo{url: urls, level: page.level + 1})
		}
	}
	return found
}

//!-sema

//!+
func main() {
	worklist := make(chan []pageInfo)
	var n int // number of pending sends to worklist

	if len(os.Args) != 4 {
		fmt.Println("Wrong usage of program, example usage is: ./web-crawler -depth=3 -results=results.txt https://google.com")
		os.Exit(1)
	}

	//substring manipulation using []rune func
	runes := []rune(os.Args[1])
	depth, err := strconv.Atoi(string(runes[7:]))
	if err != nil {
		log.Fatal(err)
	}
	runes2 := []rune(os.Args[2])
	filename := string(runes2[9:])

	n++
	go func() {
		link := os.Args[3:]
		web := make([]pageInfo, 0)
		for _, url := range link {
			web = append(web, pageInfo{url: url, level: 0})
		}
		worklist <- web
	}()
	//create text file
	file, err := os.Create(filename)
	if err != nil {
		log.Fatal(err)
	}

	// Crawl the web concurrently.
	seen := make(map[string]bool)
	for ; n > 0; n-- {
		list := <-worklist
		for _, link := range list {
			//format with \n so we dont have links right next to each other in txt file
			formatedUrl := fmt.Sprintf("%s \n", link.url)
			urlData := []byte(formatedUrl)
			_, errData := file.Write(urlData)
			if errData != nil {
				log.Printf("Could not write url: %s to file \n", link.url)
			}

			if !seen[link.url] {
				seen[link.url] = true
				if link.level < depth { //
					n++
					go func(link pageInfo) {
						worklist <- crawl(link, false)
					}(link)
				} else if link.level == depth {
					n++
					go func(link pageInfo) {
						worklist <- crawl(link, true)
					}(link)
				} else {
					fmt.Println("Desired depth reached, stopping.")
				}

			}
		}
	}
	file.Close()
}
