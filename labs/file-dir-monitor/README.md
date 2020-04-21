Lab - File/Directory Monitor
================================

Write a program that logs all file creations, deletions, and renames under the directory named in its command-line argument.
The program should monitor events in all of the subdirectories under the specified directory.

To obtain a list of all of these subdirectories, you will need to make use of [nftw()](https://linux.die.net/man/3/nftw).
When a new subdirectory is added under the tree or a directory is deleted, the set of monitored subdirectories should be updated accordingly.

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [advanced-logger](https://github.com/CodersSquad/ap-labs/tree/master/labs/advanced-logger).
- `printf` function calls are not allowed, use your logger.
- Use the `inotify` [API](http://man7.org/linux/man-pages/man7/inotify.7.html).
- Use the `monitor.c` file for implementing the lab's general flow.
- (Optional) Use the `Makefile` for compilation
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.

Tests Cases
-----------
Below you can see how your program will be tested:

1. Run as privileged user
```
sudo ./monitor /tmp
```

2. Monitor your home's directory
```
./monitor $HOME
```

3. Monitor the current path
```
./monitor $(pwd)
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
