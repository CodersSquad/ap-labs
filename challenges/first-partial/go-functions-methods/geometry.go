// Copyright © 2016 Alan A. A. Donovan & Brian W. Kernighan.
// License: https://creativecommons.org/licenses/by-nc-sa/4.0/

// See page 156.

// Package geometry defines simple types for plane geometry.
//!+point
package main

import (
	"fmt"
	"math"
	"math/rand"
	"os"
	"strconv"
)

type Point struct{ X, Y float64 }

// traditional function
func Distance(p, q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

// same thing, but as a method of the Point type
func (p Point) Distance(q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

// A Path is a journey connecting the points with straight lines.
type Path []Point

// Distance returns the distance traveled along the path.
func (path Path) Distance() float64 {
	sum := 0.0
	for i := range path {
		if i > 0 {
			sum += path[i-1].Distance(path[i])
			fmt.Printf("%v + ", path[i-1].Distance(path[i]))
		}
	}
	return sum
}

//!-point
func generatePoint() (float64, float64) {
	x := -100 + rand.Float64()*(100 - -100)
	y := -100 + rand.Float64()*(100 - -100)

	x = math.Floor(x*100) / 100
	y = math.Floor(y*100) / 100
	return x, y
}

//!+path
func validateSegments(x, y, n int) {

	fmt.Printf("- Generating a [%v] sides figure\n", n)
	fmt.Println("- Figure's vertices")

	points := make([]Point, n)
	lines := Path{}

	var intersects bool
	for i := 0; i < n; {
		x, y := generatePoint()
		p := Point{float64(x), float64(y)}
		intersects = false

		if i > 2 {
			for j := 0; j < i-2; j++ {
				isIntersection := doIntersect(points[j], points[j+1], points[i-1], p)
				if isIntersection {
					intersects = true
					break
				}
			}

		}

		if !intersects {
			points[i] = p
			fmt.Printf(" - (  %v,   %v)\n", p.X, p.Y)
			i++
		}
	}

	for i := 0; i < n; i++ {
		lines = append(lines, points[i])
	}
	lines = append(lines, points[0])
	fmt.Printf(" = %v \n", lines.Distance())
}

func onSegment(p Point, q Point, r Point) bool {

	if q.X <= math.Max(p.X, r.X) && q.X >= math.Min(p.X, r.X) &&
		q.Y <= math.Max(p.Y, r.Y) && q.Y >= math.Min(p.Y, r.Y) {
		return true
	}
	return false
}

func orientation(p Point, q Point, r Point) int {
	val := (q.Y-p.Y)*(r.X-q.X) - (q.X-p.X)*(r.Y-q.Y)

	if val == 0 {
		return 0
	} else if val > 0 {
		return 1
	} else {
		return 2
	}
}

func doIntersect(p1, q1, p2, q2 Point) bool {
	o1 := orientation(p1, q1, p2)
	o2 := orientation(p1, q1, q2)
	o3 := orientation(p2, q2, p1)
	o4 := orientation(p2, q2, q1)

	if o1 != o2 && o3 != o4 {
		return true
	}
	if o1 == 0 && onSegment(p1, p2, q1) {
		return true
	}
	if o2 == 0 && onSegment(p1, q2, q1) {
		return true
	}
	if o3 == 0 && onSegment(p2, p1, q2) {
		return true
	}
	if o4 == 0 && onSegment(p2, q1, q2) {
		return true
	}

	return false
}

func main() {
	if len(os.Args) > 1 {
		var err error
		var argc int
		if argc, err = strconv.Atoi(os.Args[1]); err != nil {
			panic(err)
		}

		validateSegments(1, 2, argc)
	} else {
		fmt.Println("Not enough arguments")
	}
}

//!-path
