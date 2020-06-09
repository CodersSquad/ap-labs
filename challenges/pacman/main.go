package main

import (
	"fmt"

	"github.com/veandco/go-sdl2/sdl"
)

const (
	screenWidth             = 800.0
	screenHeight            = 900.0
	death_sound_path        = "soundeffects/pacman_death.mp3"
	munch_sound_path        = "soundeffects/pacman_chomp.mp3"
	intermission_sound_path = "soundeffects/pacman_intermission.mp3"
	eat_fruit_sound_path    = "soundeffects/pacman_eatfruit.mp3"
	eat_ghost_sound_path    = "soundeffects/pacman_eatghost.mp3"
	extra_life_sound_path   = "soundeffects/pacman_extrapac.mp3"
	background_song_path    = "soundeffects/pacman_fever.mp3"
)

func textureFromBMP(renderer *sdl.Renderer, filename string) *sdl.Texture {
	img, err := sdl.LoadBMP(filename)
	if err != nil {
		panic(fmt.Errorf("loading %v: %v", filename, err))
	}
	defer img.Free()
	tex, err := renderer.CreateTextureFromSurface(img)
	if err != nil {
		panic(fmt.Errorf("creating texture from %v: %v", filename, err))
	}

	return tex
}

func updateTexture() {

}

func getVisualNodes(renderer *sdl.Renderer, layout [][]int) [][]visualNode {
	cellSize := screenWidth / Dimension
	// read from pacman.go layout
	//fmt.Println(cellSize)
	output := make([][]visualNode, Dimension)

	yPos := cellSize / 2.0

	for i := 0; i < Dimension; i++ {
		xPos := cellSize / 2.0
		row := make([]visualNode, Dimension)
		for j := 0; j < Dimension; j++ {
			row[j] = newNode(renderer, xPos, yPos, layout[i][j])
			xPos += cellSize
		}
		output[i] = row
		yPos += cellSize

	}
	//fmt.Println(len(output))
	return output
}

func drawVisualNodes(visualNodes [][]visualNode, renderer *sdl.Renderer, nodeLayout [][]Node) {
	for i, nodeRow := range visualNodes {
		for j, node := range nodeRow {
			node.updateTex(renderer, nodeLayout[i][j].visual)
			node.draw(renderer)
		}
	}
}
