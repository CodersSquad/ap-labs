//Scanner program A01227885

package main

//required imports

import (
  "fmt"
  "os"

  "path/filepath"

)

//declare variables, set in 0

var file int = 0;

var dev int = 0;
var sock int = 0;
var dir int = 0;
var link int = 0;

//init funcion to scan

func scan(dir string, f os.FileInfo, err error) error {

  // here we check if our file fullfills requirements, if it does we increment our values and return null

  if f.IsDir() {
    dir++;
    return nil;
  }


  if f.Mode() & os.ModeSymlink != 0 {
    link++;
    return nil;
  }


  if f.Mode().IsRegular() {
    file++;
    return nil;
  }


  if f.Mode()&os.ModeSocket != 0 {
    sock++;
    return nil;
  }


  if f.Mode()&os.ModeDevice != 0{
    dev++;
    return nil;
  }


  return nil
}

//  Dir stands for the directory scanning implementation
func scanDir(dir string) error {
  err := filepath.Walk(dir, scan);
  return err
}

//our main function

func main() {

//if the arguments is invalid we specify

  if len(os.Args) < 2 {
    fmt.Println("Usage: ./dir-scan <directory>")
    os.Exit(1)
  }

//here we just print our results

  scanDir(os.Args[1])
  fmt.Printf("Directory Scanner Tool\n" +
              "| dir:\t\t|\t%d\t|\n" +
              "| Symbolic Links:\t|\t%d\t|\n" +
              "| dev:\t\t|\t%d\t|\n" +
              "| sock:\t\t|\t%d\t|\n" +
              "| Symbolic Links:\t|\t%d\t|\n" +
              "| Other files:\t\t|\t%d\t|\n",os.Args[1], dir, link, dev, sock, link, file)
}
