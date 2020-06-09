package main

import (
	"github.com/veandco/go-sdl2/sdl"
)

const (
	playerSize = 105
)

type player struct {
	tex  *sdl.Texture
	x, y float64
}

func newPlayer(renderer *sdl.Renderer) (p player) {

	p.tex = textureFromBMP(renderer, "sprites/player.bmp")
	p.x = screenWidth / 2.0
	p.y = 850

	return p
}

func (p *player) draw(renderer *sdl.Renderer) {
	//fmt.Println("drawing plater")
	x := p.x - playerSize/2.0
	y := p.y - playerSize/2.0
	renderer.Copy(p.tex,
		&sdl.Rect{X: 0, Y: 0, W: playerSize, H: playerSize},
		&sdl.Rect{X: int32(x), Y: int32(y), W: playerSize, H: playerSize})
}
