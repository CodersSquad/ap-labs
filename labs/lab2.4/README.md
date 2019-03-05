Lab 2.4 - Add `syslog` support to your Logger
=============================================

Now it's time to add support for Linux system logging into your logger that you implemented on [lab2.2](https://github.com/CodersSquad/ap-labs/tree/master/labs/lab2.2).

A new `initLogger`function will be added in order to add support for choosing between `stdout` or `syslog` logging.

```
int initLogger(char *logType)
```

You will handle the following log types:
- `stdout` or empty string for `STDOUT` logging
- `syslog` for `SYSLOG` logging

You can use the **The Linux Programming Interface** book as a reference for your implementation. See *37th chapter on 5th section*.

General Requirements and Considerations
---------------------------------------
- Use the `testLogger.c` file for testing your `logger.c` library implementation.
- Use the `Makefile` for compilation.
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
Expected  output:
```
{"message":"Welcome obedmr","user":"obedmr"}
```


## Submit your lab
**Note:** Before submitting, make sure you do the common `git add`, `git commit` and `git push` for the new code changes in your `ap-labs` repository.
```
curl -k -X POST -d "commit=$(git rev-parse --short master)" https://classify-232805.appspot.com/labs/obedmr/lab2.4
```

Expected sample output:
```
{"commit":"755667f","dueDate":"Tue Mar 12 23:59:00 2019","labID":"lab2.4","message":"Submission Accepted","submissionDate":"Mon Mar  4 21:45:29 2019","user":"obedmr"}
```


## Check your Lab's submission
```
curl -k https://classify-232805.appspot.com/labs/obedmr/lab2.4
```

Expected sample output:
```
{"message":"Lab's submission data was successfully retrieved","submission":{"ID":"obedmr.lab2.4","LabID":"lab2.4","CommitID":"755667f","Date":"2019-03-05T03:45:29.500133921Z"},"user":"obedmr"}
```
