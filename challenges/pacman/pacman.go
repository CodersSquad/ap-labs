package main

import (
	"flag"
	"fmt"
	"math/rand"
	"os"
	"time"

	"github.com/veandco/go-sdl2/sdl"
	"github.com/veandco/go-sdl2/ttf"
)

/*
TILES:
0 -> WALL
1 -> WALKABLE

ENTITY:
EMPTY -> 0
PACMAN -> 1
GHOST -> 2

VISUAL:
0 -> WALL
1 -> DOT WALKABLE
2 -> EMPTY WALKABLE
3 -> PACMAN
4 -> GHOST

DIRECTION:
NONE -> -1
RIGHT -> 0
UP -> 1
LEFT -> 2
DOWN -> 3
*/

var (
	coins        int
	points       int
	solidTexture *sdl.Texture
	solidSurface *sdl.Surface
)

// Node is a tile
type Node struct {
	tile   int
	entity int
	hasDot bool
	i      int
	j      int
	visual int
	next   []*Node
}

// Pacman is the player
type Pacman struct {
	direction     int
	nextDirection int
	currentNode   *Node
	dead          bool
}

func (p *Pacman) walk() {
	if p.dead {
		return
	}

	temp := Node{}
	next := &temp

	switch p.nextDirection {
	case 0:
		if p.currentNode.j < Dimension-1 {
			next = &nodeLayout[p.currentNode.i][p.currentNode.j+1]
		}
	case 1:
		if p.currentNode.i > 0 {
			next = &nodeLayout[p.currentNode.i-1][p.currentNode.j]
		}
	case 2:
		if p.currentNode.j > 0 {
			next = &nodeLayout[p.currentNode.i][p.currentNode.j-1]
		}
	case 3:
		if p.currentNode.i < Dimension-1 {
			next = &nodeLayout[p.currentNode.i+1][p.currentNode.j]
		}
	}

	if next.tile != 1 {
		switch p.direction {
		case 0:
			if p.currentNode.j < Dimension-1 {
				next = &nodeLayout[p.currentNode.i][p.currentNode.j+1]
			}
		case 1:
			if p.currentNode.i > 0 {
				next = &nodeLayout[p.currentNode.i-1][p.currentNode.j]
			}
		case 2:
			if p.currentNode.j > 0 {
				next = &nodeLayout[p.currentNode.i][p.currentNode.j-1]
			}
		case 3:
			if p.currentNode.i < Dimension-1 {
				next = &nodeLayout[p.currentNode.i+1][p.currentNode.j]
			}
		}
	} else {
		p.direction = p.nextDirection
	}

	p.nextDirection = -1

	if next.tile != 1 {
		return
	}

	if next.entity == 2 {
		p.currentNode.entity = 0
		p.currentNode.visual = 2
		p.dead = true
		gameover()
	}

	p.currentNode.entity = 0
	p.currentNode.visual = 2
	//visualNodes[p.currentNode.i][p.currentNode.j].updateTex(renderer, p.currentNode.visual)

	p.currentNode = next
	p.currentNode.entity = 1

	if p.currentNode.hasDot {
		coins--
		points += 100
		createFont(renderer, "")
		//fmt.Println("coins: ", coins)
		if coins < 1 {
			p.currentNode.hasDot = false
			p.currentNode.visual = 3
			win()
		}
	}

	p.currentNode.hasDot = false
	p.currentNode.visual = 3
	//visualNodes[p.currentNode.i][p.currentNode.j].updateTex(renderer, p.currentNode.visual)
}

func (p *Pacman) move() {
	//visualNodes[p.currentNode.i][p.currentNode.j].updateTex(renderer, p.currentNode.visual)
	for {
		//printLayout()
		p.walk()
		time.Sleep(200 * time.Millisecond)
		for event := sdl.PollEvent(); event != nil; event = sdl.PollEvent() {
			switch t := event.(type) {
			case *sdl.KeyboardEvent:
				//fmt.Printf("type:%d\tsym:%d\n", t.Type, t.Keysym.Sym)
				switch t.Keysym.Sym {
				case ArrowDown:
					//fmt.Println("down")
					p.nextDirection = 3
				case ArrowUp:
					//fmt.Println("up")
					p.nextDirection = 1
				case ArrowLeft:
					//fmt.Println("left")
					p.nextDirection = 2
				case ArrowRight:
					//fmt.Println("right")
					p.nextDirection = 0
				}

			case *sdl.QuitEvent:
				fmt.Println("finish")
				//done <- 0
				os.Exit(1)
			}
		}
	}
}

// Ghost is the enemy
type Ghost struct {
	currentNode *Node
	seen        map[*Node]bool
	path        *[]*Node
}

func (g *Ghost) walk(direction int) {

	temp := Node{}
	next := &temp

	switch direction {
	case 0:
		if g.currentNode.j < Dimension-1 {
			next = &nodeLayout[g.currentNode.i][g.currentNode.j+1]
		}
	case 1:
		if g.currentNode.i > 0 {
			next = &nodeLayout[g.currentNode.i-1][g.currentNode.j]
		}
	case 2:
		if g.currentNode.j > 0 {
			next = &nodeLayout[g.currentNode.i][g.currentNode.j-1]
		}
	case 3:
		if g.currentNode.i < Dimension-1 {
			next = &nodeLayout[g.currentNode.i+1][g.currentNode.j]
		}
	}

	if next.tile != 1 {
		return
	}

	if next.entity == 1 {
		g.currentNode.entity = 0
		if g.currentNode.hasDot {
			g.currentNode.visual = 1
		} else {
			g.currentNode.visual = 2
		}

		g.currentNode = next
		g.currentNode.entity = 2
		g.currentNode.visual = 4
		pacman.dead = true
		gameover()
	}

	g.currentNode.entity = 0
	if g.currentNode.hasDot {
		g.currentNode.visual = 1
	} else {
		g.currentNode.visual = 2
	}

	g.currentNode = next
	g.currentNode.entity = 2
	g.currentNode.visual = 4
}

func (g *Ghost) moveToPacman() {
	if len(*g.path) < 1 {

		g.seen = make(map[*Node]bool, 0)
		g.seen[g.currentNode] = true

		tmp := make([]*Node, 0)
		g.getNextNode(g.currentNode, &tmp)
		//fmt.Println("the length: ", len(*g.path))
		/*for _, k := range *g.path {
			//fmt.Printf("uwu: %d, %d\n", k.i, k.j)
		}*/
		//g.moveToPacman()
	} else {
		g.walk(getAdjacentDirection(g.currentNode, (*g.path)[0]))
		//fmt.Println(len(*g.path))
		tmp := (*g.path)[1:]
		g.path = &tmp
	}

	time.Sleep(200 * time.Millisecond)
	g.moveToPacman()
}

func (g *Ghost) getNextNode(node *Node, path *[]*Node) *[]*Node {
	//fmt.Printf("%d, %d  %d\n", node.i, node.j, len(path))

	if node.entity == 1 {
		//fmt.Printf("%d, %d  %d\n", node.i, node.j, len(*path))
		return path
	}

	for _, i := range node.next {
		if i.tile == 1 {
			if g.seen[i] {
				continue
			}

			g.seen[i] = true
			//fmt.Println("i:", i.i)
			//fmt.Println("yes: ", i.j)
			tmp2 := append(*path, i)
			temp := g.getNextNode(i, &tmp2)
			//fmt.Println(temp.i, temp.j)
			if len(*temp) > 0 && (*temp)[len(*temp)-1].entity == 1 {
				g.path = temp
				return path
			}
		}
	}

	tmp := make([]*Node, 0)
	return &tmp
}

// Dimension of the gmae
const (
	Dimension  = 25
	ArrowDown  = 1073741905
	ArrowUp    = 1073741906
	ArrowLeft  = 1073741904
	ArrowRight = 1073741903
)

var layout = [][]int{
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}

var nodeLayout [][]Node
var pacman Pacman
var ghosts []*Ghost
var visualNodes [][]visualNode
var renderer *sdl.Renderer
var plr player

var done chan int

func main() {
	rand.Seed(time.Now().UnixNano())

	ghostNum := flag.Int("n", 5, "an int: number of ghosts")
	flag.Parse()
	ttf.Init()
	createNodes()
	createPacman()

	createGhosts(*ghostNum)

	for _, i := range ghosts {
		//fmt.Println("at main:", i)
		go i.moveToPacman()
	}

	<-done
}

func gameover() {
	//fmt.Println("you dead")
	createFont(renderer, "You Lose!!")
	time.Sleep(4000 * time.Millisecond)
	//done <- 0
	os.Exit(1)
}

func win() {
	//fmt.Println("ganar")
	//done <- 0
	createFont(renderer, "You Win!!")
	time.Sleep(5000 * time.Millisecond)
	os.Exit(1)
}

func getAdjacentDirection(node1, node2 *Node) int {
	if node1.j < node2.j {
		return 0
	} else if node1.i > node2.i {
		return 1
	} else if node1.j > node2.j {
		return 2
	} else {
		return 3
	}
}

func createNodes() {
	coins = 0
	nodeLayout = make([][]Node, Dimension)
	for i := range layout {
		nodeLayout[i] = make([]Node, Dimension)
		for j := range layout[i] {
			if layout[i][j] == 1 {
				coins++
			}

			nodeLayout[i][j] = Node{tile: layout[i][j], hasDot: true, i: i, j: j, visual: layout[i][j], next: make([]*Node, 4)}
			temp := Node{}
			for k := range nodeLayout[i][j].next {
				nodeLayout[i][j].next[k] = &temp
			}

			if i > 0 {
				nodeLayout[i-1][j].next[3] = &nodeLayout[i][j]
				nodeLayout[i][j].next[1] = &nodeLayout[i-1][j]
			}

			if j > 0 {
				nodeLayout[i][j-1].next[0] = &nodeLayout[i][j]
				nodeLayout[i][j].next[2] = &nodeLayout[i][j-1]
			}
		}
	}
	go visualSetup()
}

func createPacman() {
	pacman = Pacman{nextDirection: -1, currentNode: randomEmptyWalkableTile(), dead: false}
	pacman.currentNode.entity = 1
	pacman.currentNode.hasDot = false
	pacman.currentNode.visual = 3

	coins--
	points += 100
	//createFont(renderer)
}

func createGhosts(n int) {
	ghosts = make([]*Ghost, n)

	for i := range ghosts {
		tmp := make([]*Node, 0)
		ghosts[i] = &Ghost{currentNode: randomEmptyWalkableTile(), path: &tmp}
		ghosts[i].currentNode.entity = 2
		ghosts[i].currentNode.visual = 4
		//visualNodes[ghosts[i].currentNode.i][ghosts[i].currentNode.j].updateTex(renderer, ghosts[i].currentNode.visual)
	}

	//fmt.Println("lal: ", ghosts)
}

func randomEmptyWalkableTile() *Node {
	temp := Node{}
	node := &temp

	for node.tile != 1 || node.entity != 0 {
		node = &nodeLayout[rand.Intn(Dimension)][rand.Intn(Dimension)]
	}

	return node
}

func printLayout() {
	for _, i := range nodeLayout {
		for _, j := range i {
			fmt.Printf("%d \t", j.visual)
		}
		fmt.Println()
	}
	fmt.Println()
}

func visualSetup() {
	if err := sdl.Init(sdl.INIT_EVERYTHING); err != nil {
		fmt.Println("initializing SDL:", err)
		return
	}

	window, err := sdl.CreateWindow(
		"Pacman",
		sdl.WINDOWPOS_UNDEFINED, sdl.WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		sdl.WINDOW_OPENGL)
	if err != nil {
		fmt.Println("initializing window:", err)
		return
	}
	defer window.Destroy()

	renderer, err = sdl.CreateRenderer(window, -1, sdl.RENDERER_SOFTWARE)
	if err != nil {
		fmt.Println("initializing renderer:", err)
		return
	}
	//fmt.Println("renderer created")
	defer renderer.Destroy()

	initTex(renderer)
	//plr = newPlayer(renderer)

	visualNodes = getVisualNodes(renderer, layout)
	/*for _, i := range ghosts {
		visualNodes[i.currentNode.i][i.currentNode.j].updateTex(renderer, i.currentNode.visual)
	}*/
	go pacman.move()

	for {
		//fmt.Println("uwu")
		/*for event := sdl.PollEvent(); event != nil; event = sdl.PollEvent() {
			switch event.(type) {

		}*/

		renderer.SetDrawColor(0, 0, 0, 0)
		renderer.Clear()

		//plr.draw(renderer)
		drawVisualNodes(visualNodes, renderer, nodeLayout)
		drawFont()

		renderer.Present()
	}

}

func createFont(renderer *sdl.Renderer, text string) {
	var font *ttf.Font
	var err error

	if font, err = ttf.OpenFont("font/Symtext.ttf", 40); err != nil {
		fmt.Printf("Failed to open font: %s\n", err)
		return
	}
	if len(text) < 1 {
		if solidSurface, err = font.RenderUTF8Solid(fmt.Sprintf("Score: %d", points), sdl.Color{R: 255, G: 255, B: 255, A: 255}); err != nil {
			fmt.Printf("Failed to render text: %s\n", err)
			return
		}
	} else {
		if solidSurface, err = font.RenderUTF8Solid(text, sdl.Color{R: 255, G: 255, B: 255, A: 255}); err != nil {
			fmt.Printf("Failed to render text: %s\n", err)
			return
		}
	}

	if solidTexture, err = renderer.CreateTextureFromSurface(solidSurface); err != nil {
		fmt.Printf("Failed to create texture: %s\n", err)
		return
	}

	solidSurface.Free()

	font.Close()

}

func drawFont() {
	renderer.Copy(solidTexture, nil, &sdl.Rect{W: 800, H: 100, X: 0, Y: 800})
}
