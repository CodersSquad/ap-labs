package main

import (
	"github.com/veandco/go-sdl2/sdl"
)

// relacionar numero de estado con sprite

const (
	nodeSize = 32
)

var (
	ghostTex  *sdl.Texture
	wallTex   *sdl.Texture
	coinTex   *sdl.Texture
	emptyTex  *sdl.Texture
	pacmanTex *sdl.Texture
)

type visualNode struct {
	tex  *sdl.Texture
	x, y float64
}

func initTex(renderer *sdl.Renderer) {
	wallTex = textureFromBMP(renderer, "sprites/tile005.bmp")
	coinTex = textureFromBMP(renderer, "sprites/tile003.bmp")
	emptyTex = textureFromBMP(renderer, "sprites/tile002.bmp")
	pacmanTex = textureFromBMP(renderer, "sprites/tile00.bmp")
	ghostTex = textureFromBMP(renderer, "sprites/tile004.bmp")
}

func (n *visualNode) updateTex(renderer *sdl.Renderer, visual int) {
	switch visual {
	case 0:
		n.tex = wallTex
	case 1:
		n.tex = coinTex
	case 2:
		n.tex = emptyTex
	case 3:
		n.tex = pacmanTex
	case 4:
		n.tex = ghostTex
	}
}

func newNode(renderer *sdl.Renderer, xcoord float64, ycoord float64, visual int) (n visualNode) {

	switch visual {
	case 0:
		n.tex = textureFromBMP(renderer, "sprites/tile005.bmp")
	case 1:
		n.tex = textureFromBMP(renderer, "sprites/tile003.bmp")
	}
	n.x = xcoord
	n.y = ycoord

	return n
}

func changeTex() {

}

func (n *visualNode) draw(renderer *sdl.Renderer) {
	x := n.x - nodeSize/2.0
	y := n.y - nodeSize/2.0
	renderer.Copy(n.tex,
		&sdl.Rect{X: 0, Y: 0, W: nodeSize, H: nodeSize},
		&sdl.Rect{X: int32(x), Y: int32(y), W: nodeSize, H: nodeSize})
}
