Lab 2.2 - Logger Library
========================

Implement a Logger library in C that will be used for printing the following types of messages.
- `INFO` General information.
- `WARN` Warnings.
- `ERROR` Errors.
- `PANIC` Panics. Non recoverable issues with core dump.

This `logger` library will be used instead of `printf` function calls in all new labs and challenges that we'll be doing in the course.
Below you can see the prototype for each function.

```
int infof(const char *format, ...)
int warnf(const char *format, ...)
int errorf(const char *format, ...)
int panicf(const char *format, ...)
```

General Requirements and Considerations
---------------------------------------
- Use the `logger.c` file for your implementation.
- Update `README.md` with the proper steps for building and running your code.
- Use the `testLogger.c` file for testing all your logger functions.
- Use different font color for each of the log types. For colors references go to: https://www.linuxjournal.com/article/8603
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
curl -k -X POST -d "commit=$(git rev-parse --short master)" https://classify-232805.appspot.com/labs/obedmr/lab2.2
```

Expected output:
```
{"commit":"755667f","dueDate":"Tue Mar 12 23:59:00 2019","labID":"lab2.2","message":"Submission Accepted","submissionDate":"Mon Mar  4 21:45:29 2019","user":"obedmr"}
```


## Check your Lab's submission
```
curl -k https://classify-232805.appspot.com/labs/obedmr/lab2.2
```

Expected output:
```
{"message":"Lab's submission data was successfully retrieved","submission":{"ID":"obedmr.lab2.2","LabID":"lab2.2","CommitID":"755667f","Date":"2019-03-05T03:45:29.500133921Z"},"user":"obedmr"}
```
