# Pacman's architecture file

This program works by using the following components:

## Structs

### Node
This struct is used to define the properties of each tile in the game's maze
Node's fields are described next:
* `tile int`. Defines whether the player can walk through it or not by using values 1 and 0, respectively.
* `entity int`. Defines if the player, an enemy or none are currently positioned in the tile. 1, 2 and 0, respectively.
* `hasDot bool`. If the tile is walkable, this field defines whether or not its coin is still to be collected.
* `i int`. Defines the vertical position of the tile within the layout.
* `j int`. Defines the horizontal position of the tile within the layout.
* `visual int`. This field helps deciding what sprite should be displayed.
  * 0 -> Wall (not walkable)
  * 1 -> Walkable with dot
  * 2 -> Empty walkable
  * 3 -> Player
  * 4 -> Ghost
* `next []*Node`. Contains all of the adjacent walkable tiles to aid the movement processes.

### Pacman
This struct contains information about the player's position and movement.
Its fields are:
* `direction int`. Determines the direction the player is currently heading.
  * -1 -> None
  * 0 -> Right
  * 1 -> Up
  * 2 -> Left
  * 3 -> Down
* `nextDirection int`. Helps deciding whether or not the player can move towards a relative direction. Uses the sames values as direction.
* `currentNode *Node`. A pointer to the player's current Node (position).
* `dead bool`. Restricts movement when the player has lost the game.

### Ghost
This struct represent each of the enemies in the game.
Ghost's fields are:
- `currentNode *Node`. A pointer to the ghost's current position.
- `seen map[*Node]bool`. A map from Node pointers to bool that aids the path-finding algorithm.
- `path *[]*Node`. Determines the path that the ghost will follow to try to reach the player.

### Visual structs		
Other structs were created to build the game's GUI. They are all very similar and contain the same fields:
- `x int`. Horizontal position of the sprite.
- `y int`. Vertical position of the sprite.
- `tex *sdl.Texture`. The texture to be displayed.

We use a square `int` matrix called layout to create the maze according to the values defined in Node's `tile` field. It is then used to create `nodeLayout`, a `Node` matrix of the same size. Next, an instance of the `Pacman` struct is created and positioned in a random walkable tile, followed by the same process applied to a user-defined number of ghosts. A goroutine is started for each of the created entities' movement, the GUI is displayed and an `int` channel called `done` is put on wait for the game to finish.

## Movement methods

Both the player's and the ghosts' movement methods work in a similar way.

### Pacman
Pacman's `move()` method is called as a goroutine. It contains an infinite loop which performs two things: calls the `walk()` method (explained below) and listens to the player's input every 0.2 seconds to either change pacman's `nextDirection` value or quit the game.
Pacman's `walk()` method takes the current value of `nextDirection`, changed by the player's input from the arrow keys. Then, it checks a couple of things: first, that the intended movement doesn't exceed the maze's limits, and second, that the corresponding tile is walkable. Once succeeded, the value of the `direction` field is changed to match this last movement and the `visual` field of both the current and next tiles is updated accordingly.

### Ghost
Ghosts' `moveToPacman()` method uses a DepthFirstSearch algorithm to trace and follow a route towards the player, once it reaches the traced position this algorithm is used again. It moves every 0.2 seconds by using the method `walk()`, which is essentially the same as Pacman's, with the exception that the `visual` fields are preserved.

If either a ghost collides with the player or viceversa, the channel `done` receives a signal and the game ends.

For every coin that the player collects, the score increases. The game is won once all coins have been collected without colliding with any ghosts.
