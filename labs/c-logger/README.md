Lab - Logger Library
====================

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

General instructions
--------------------
- Use the `logger.c` file for your implementation.
- Update `README.md` with the proper steps for building and running your code.
- Use the `testLogger.c` file for testing all your logger functions.
- Use different font color for each of the log types. For colors references go to: https://www.linuxjournal.com/article/8603
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.

How to submit your work
=======================
```
make submit
```
More details at: [Classify API](../../classify.md)
