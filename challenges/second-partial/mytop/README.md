MyTop
=====
Implement a new version of the `top` tool. The only source of information about processes  will be the `/proc` filesystem. This should be a real-time application that automatically updates the dashboard with new and terminated processes. Below more details about the requirements.

Requirements
------------
- The program must be implemented in C programming language.
- Use the provided template `mytop.c`
- As a realtime app, screen should be automatically updated with any change in processes.
- A multi-threaded implementation can be used here.
- [OPTIONAL] Add support for current processes dashboard snapshots to file (mytop-status-XXXXXX).
  - Use the `SIGINT` to capture the current processes dashboard
  - Save the current processes dashboard to a new file mytop-status-DATE
- You need to follow the output format guidelines.
- Coding best practices that we learned in class will be reviewed.
- Before submitting you code, make sure it's compiling and running correctly.


Sample mytop output
-------------------
```
# ./mytop
| PID   | Parent | Name           | State    | Memory | # Threads | Open Files |
|-------|--------|----------------|----------|--------|-----------|------------|
| 120   | 1      | sshd           | Active   | 120M   | 1         | 5          |
| 3453  | 120    | sshd-child     | Sleeping | 4M     | 1         | 0          |
| 433   | 433    | single-process | Active   | 15M    | 2         | 1          |
| 3434  | 34     | multi-threads  | Active   | 1020M  | 4         | 5          |
| 16887 | 16886  | test-app       | Sleeping | 17M    | 1         | 7          |
```

Grading
-------
| Requirement                    |      |
|--------------------------------|------|
| Process IDs (PID and Parent)   | 20%  |
| State, Memory & # of Threads   | 20%  |
| Open Files                     | 20%  |
| MyTop Status Snapshots         | 20%  |
| Coding best practices          | 20%  |
| TOTAL                          | 100% |

Useful links and resources
--------------------------
- https://www.tldp.org/LDP/Linux-Filesystem-Hierarchy/html/proc.html
- `man proc` command
- `/proc/<PID>/status` per-process file
