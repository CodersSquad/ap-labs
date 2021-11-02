Multithreaded Snakes Game
=========================

Implement a multithreaded version of the video game [Snake](https://en.wikipedia.org/wiki/Snake_(video_game_genre)). This version will be a
Computer vs Human game. Each enemy will be independent and the number of enemies is configurable. Below you can see the general
requirements for the enemies and human player (snake) interation.

![Snakes](snakes.png)

Technical Requirements
----------------------
- The game's layout can be static.
- Food dots can be randomly located in the layout.
- Number of food dots must be configured in the game's tart.
- The main `snake` gamer must be controlled by the user.
- Enemy snakes are autonomous entities that will move a random way.
- Enemy snakes and main snake should respect the layout limits and walls.
- Enemy snakes number can be configured on game's start.
- Each enemy's behaviour will be implemented as a separated thread.
- Enemy snakes and main sneak threads must use the same map or game layout data structure resource.
- Display obtained main snake's scores.
- Main snake grow one unit on every eaten food dot.
- Enemy snakes can also grow when they touch food dots.
- Main snake loses when it has been hit 10 times by other snake or it touches the limits or walls.
- Main snake wins the game when all food dots have eaten and main snake has the largest lenght.

General Requirements
--------------------
- Source code must be hosted in the class `ap-labs` repository.
- Make sure that you complete the below defined deliverables.
- Source code dependencies must be clearly documented.

Deliverables
------------
- Source code in each team's member repository (`ap-labs/challenges/snakes`).
- Architecture Document - [ARCHITECTURE.md](ARCHITECTURE.md)
- Build/Run automation (`Makefile` and documentation - [SNAKES.md](SNAKES.md))
- Project's presentation (5-10 minutes)


Permitted programming languages
-------------------------------
- Multithreaded core backend
  - C
  - Go
- User Interface (optional)
  - Any
  - If it's terminal, output must be human-readable

Submission Details
------------------
- Read [Classify API](../../classify.md)

Grading Policy
--------------
| Concept                      | Grade |
|------------------------------|-------|
| Architecture Document        | 20%   |
| Multithreaded implementation | 30%   |
| Build Automation             | 20%   |
| Coding best practices        | 10%   |
| Presentation                 | 20%   |
| TOTAL                        | 100%  |

- **Free Bonus Lab**

  You can get an extra bonus if you implement an Artificial Intelligence algorithm in enemies behaviour
  for finding the main snake location, trace the route and follow it.