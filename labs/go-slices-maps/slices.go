package main

import "code.google.com/p/go-tour/pic"

func Pic(dx, dy int) [][]uint8 {

	slice := make([][]uint8, dy)
	
	for x := 0; x < dy; x++ {
	
		slice[x] = make([]uint8, dx)
		
	}
  
	for x := 0; x < dy; x++ {
	
		for y := 0; y < dx; y++ {
		
			slice[x][y] = uint8(x*y)
			
		}
	}
	return slice
}

func main() {
	pic.Show(Pic)
}
