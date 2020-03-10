Pacman Analyzer
===============
[Pacman](https://wiki.archlinux.org/index.php/pacman) is the official package manager in the ArchLinux GNU/Linux distribution. You will
implement an analyzer for the pacman packages management log.

On this challenge you will implement a system log analyzer and classifier for the ArchLinux's package manager (pacman).
In this particular case, a sample log output file is provided. This challenge involves a proper struct design choice for the packages data storing.


Requirements
------------
- The program must be implemented in C programming language.
- You program will discover all pacman-managed packages alongside all their active, from installation to removal.
- Use the `pacman-analyzer.c` template
- The solution must use at least 3 of the following system calls:
  - `open()`
  - `read()`
  - `write()`
  - `lseek()`
  - `close()`
- You're not allowed to use the `getline` function. You will implement you're own `getline` function.
- You need to follow the output format guidelines.
- [Coding best practices](https://softfire-143705.appspot.com/programming-art/00-names.slide#1) that we learned in class will be reviewed.
- Before submitting you code, make sure it's compiling and running correctly.


Sample execution and expected output file `packages_report.txt`
------------------------------------------------

**Note:** The following report is not containing real values from the original [`pacman.txt`](./pacman.txt) file. This is just an example. 

```
$ ./pacman-analizer pacman.txt
Pacman Packages Report
----------------------
- Installed packages : 150
- Removed packages   : 30
- Upgraded packages  : 90
- Current installed  : 120

List of packages
----------------
- Package Name        : gcc
  - Install date      : 2019-02-02 13:29
  - Last update date  : 2019-09-02 13:29
  - How many updates  : 3
  - Removal date      : -
- Package Name        : ruby-erubis
  - Install date      : 2019-02-02 14:23
  - Last update date  : 2019-09-01 12:39
  - How many updates  : 5
  - Removal date      : 2019-09-01 12:39
.
.
.
```


Test Cases
----------

The program will be tested with the following log file:

1. [pacman.txt](./pacman.txt)
```
$ ./pacman-analyzer pacman.txt
```
