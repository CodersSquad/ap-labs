Lab - Progress Notifier with Signals
========================================
Implement a program for encoding and decoding files by using the `Base64` [algorithm](https://en.wikibooks.org/wiki/Algorithm_Implementation/Miscellaneous/Base64).
You're free to copy from  previous link's implementation (don't forget to reference to the author's page), the interesting part will be the implementation of signal handlers for progress status.

Add one or multiple signal handlers to catch the `SIGUSR1` and `SIGINT`. Once a signal is catched, your program should display the current progress of the encoding or deconding tasks.

You will need the proper mechanisms for tracking the progress of any encoding/decoding task. You program must support plain text input files.


Encoding
--------
```
./base64 --encode input.txt
```
Your program should generate a new `input-encoded.txt` file with the result. The encoded file name must have the following naming convention `<input-file>-encoded.txt`.


Decoding
--------
```
./base64 --decode input-encoded.txt
```
Your program will generate a `input-decoded.txt` file witg the result. The decoded file name must have the following naming convention `<input-file>-decoded.txt`.


How to test?
------------
- Get process ID
```
ps aux | grep base64
```

- Send the signals
```
kill -SIGINT <PID>
kill -SIGUSR1 <PID>
```

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [advanced-logger](https://github.com/CodersSquad/ap-labs/tree/master/labs/advanced-logger).
- `printf` function calls are not allowed, use your logger
- Use the `base64.c` file for implementing the lab's general flow.
- Use the `Makefile` for compilation.
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
```
make test
```


How to submit your work and check your submission
=================================================
```
# Clean binaries and temporal test files
make clean

# Submit
make submit

# Check Submission
make check-submission
```

More details about Classify API : [Classify](../../classify.md)
