Multithreaded Earthquake Simulator
==================================

Implement a multithreaded earthquake simulator where every person in a building floor must walk out of the building by the
emergency exits.

![Earthquake Simulater](earthquake.png)

Technical Requirements
----------------------
- The building's map can be static or automatically generated.
- We're considering a 1-floor building.
- Each person's behaviour must be implemented in a separated thread.
- Building map is a shared resource across all people threads.
- Number of people and emergency exits in the building is defined in the simulation's start.
- Emergency exits are randomly located.
- Every person emergency walk out route is randomply generated to the first found exit.
- Each person will have his/her own walking speed.
- If a person finds another person on his/her path, he/she must slow down in case that the front person's walk is slower.
- Define a timeout for walking out of the building.
- Display safe people and trapped people after earthquake timeout.

General Requirements
--------------------
- Source code must be hosted in the class `ap-labs` repository.
- Make sure that you complete the below defined deliverables.
- Source code dependencies must be clearly documented.

Deliverables
------------
- Source code in each team's member repository (`ap-labs/challenges/earthquake`).
- Architecture Document - [ARCHITECTURE.md](ARCHITECTURE.md)
- Build/Run automation (`Makefile` and documentation - [EARTHQUAKE.md](EARTHQUAKE.md))
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

  You can get an extra bonus if you implement an Artificial Intelleigence algorithm for finding the closest emergency exit.