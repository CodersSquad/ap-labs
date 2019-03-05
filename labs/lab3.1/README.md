Lab 3.1 - File/Directory Monitor
================================

Write a program that logs all file creations, deletions, and renames under the directory named in its command-line argument.
The program should monitor events in all of the subdirectories under the specified directory.
To obtain a list of all of these subdirectories, you will need to make use of [nftw()](https://linux.die.net/man/3/nftw).
When a new subdirectory is added under the tree or a directory is deleted, the set of monitored subdirectories should be updated accordingly.

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [lab2.4](https://github.com/CodersSquad/ap-labs/tree/master/labs/lab2.4).
- Use the `monitor.c` file for implementing the lab's general flow.
- Use the `Makefile` compilation automation.
- Update `README.md` with the proper steps for building and running your code.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.


Submission Details
==================

**NOTE:** I'm using my user `obedmr` for show casing purposes. Your real submission should use your github user account in lower case.

## Check Classify API
```
curl -k https://classify-232805.appspot.com/users/obedmr
```
Expected sample output:
```
{"message":"Welcome obedmr","user":"obedmr"}
```


## Submit your lab
**Note:** Before submitting, make sure you do the common `git add`, `git commit` and `git push` for the new code changes in your `ap-labs` repository.
```
curl -k -X POST -d "commit=$(git rev-parse --short master)" https://classify-232805.appspot.com/labs/obedmr/lab3.1
```

Expected sample output:
```
{"commit":"755667f","dueDate":"Tue Mar 12 23:59:00 2019","labID":"lab3.1","message":"Submission Accepted","submissionDate":"Mon Mar  4 21:45:29 2019","user":"obedmr"}
```


## Check your Lab's submission
```
curl -k https://classify-232805.appspot.com/labs/obedmr/lab3.1
```

Expected sample output:
```
{"message":"Lab's submission data was successfully retrieved","submission":{"ID":"obedmr.lab3.1","LabID":"lab3.1","CommitID":"755667f","Date":"2019-03-05T03:45:29.500133921Z"},"user":"obedmr"}
```
