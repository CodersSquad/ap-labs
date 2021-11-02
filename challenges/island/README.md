Multithreaded Raining Balls Island Simulator
============================================

Implement a multithreaded raining simulator. Imagine that baseball balls are raining on a desert island.
Balls will randomply falling on different positions of the island. Your program will simulate each ball's
behaviour on their track from the moment they touch the island until the momment they stop moving in a valley
or they sink into the ocean.

![Ranning Balls Island](island.png)

Technical Requirements
----------------------
- The island's map can be static or automatically generated.
- Each ball's behaviour must be implemented in a separated thread.
- Island map is a shared resource across all balls threads.
- Number of balls in the raining is defined in the simulation's start.
- Balls' movement will be based on the heights arround it.
- Balls will move if (current_height >= next_position_height) where next_position can be north, south, east or west.
- Each ball will increase its speed when it goes to a lower height (You can use gravity constant).
- If 2 balls collide, they will randomly change their direction, no matter if the new position is higher.
- Display the number of balls that are in sea north, south, east and west sides. And also, display how many balls
were trapped in the island.

General Requirements
--------------------
- Source code must be hosted in the class `ap-labs` repository.
- Make sure that you complete the below defined deliverables.
- Source code dependencies must be clearly documented.

Deliverables
------------
- Source code in each team's member repository (`ap-labs/challenges/island`).
- Architecture Document - [ARCHITECTURE.md](ARCHITECTURE.md)
- Build/Run automation (`Makefile` and documentation - [ISLAND.md](ISLAND.md))
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

- **Free Lab Bonus**

  You can get an extra bonus if you implement an Artificial Intelleigence algorithm for detecting lakes formation.
  Ask for more details about this requirement.