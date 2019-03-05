Lab 2.4 - Add `syslog` support to you Logger
============================================

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
- Use the `Makefile` compilation automation.
- Update `README.md` with the proper steps for building and running your code.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.
