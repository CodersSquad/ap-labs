Lab - File/Directory Monitor
================================

Write a program that logs all file creations, deletions, and renames under the directory named in its command-line argument.
The program should monitor events in all of the subdirectories under the specified directory.

To obtain a list of all of these subdirectories, you will need to make use of [nftw()](https://linux.die.net/man/3/nftw).
When a new subdirectory is added under the tree or a directory is deleted, the set of monitored subdirectories should be updated accordingly.

**Note:** Monitor will only watch until 2nd level of the base directory tree.

**Sample Output**
```
./monitor $HOME
Starting File/Directory Monitor on /home/cs-user/dir1
-----------------------------------------------------
- [File - Create] - example.txt
- [File - Removal] - example.txt
- [Directory - Create] - subdir
- [File Create] - example2.txt 
- [File Rename] - example2.txt -> example3.txt 
- [File Create] - subdir/example_in_subdir.txt 
```

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [advanced-logger](https://github.com/CodersSquad/ap-labs/tree/master/labs/advanced-logger).
- `printf` function calls are not allowed, use your logger.
- Use the `inotify` [API](http://man7.org/linux/man-pages/man7/inotify.7.html).
- Use the `monitor.c` file for implementing the lab's general flow.
- (Optional) Use the `Makefile` for compilation
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.


Test Suite
----------
Build and Test automation is already implemented with the following command. Below some general tips and comments.

- Make sure that your program passes all test cases without errors.
- Remember that this is being executed by a robot script.
- You cannot edit the `lab.mk` file.
- Failed compilation or segmentation faults means 0-graded.
- Failed tests without proper handling  will be properly discounted from total grade.

Your program will be tested with the following cases:

**Test 1**
 ```
 sudo ./monitor /tmp
 ```
**Test 2**
 ```
./monitor ${HOME}
```
**Test 3**
```
./monitor ${PWD}
```
**Test 4** - failed
```
./monitor
```

How to submit your work and check your submission
=================================================
```
# Submit
GITHUB_USER=<your_github_user> make submit

# Check Submission
GITHUB_USER=<your_github_user> make check-submission
```

More details about Classify API : [Classify](../../classify.md)
