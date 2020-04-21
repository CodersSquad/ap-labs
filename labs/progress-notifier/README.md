Lab - Progress Notifier with Signals
========================================
Implement a program for encoding and decoding files by using the `Base64` [algorithm](https://en.wikibooks.org/wiki/Algorithm_Implementation/Miscellaneous/Base64).
You're free to copy from  previous link's implementation (don't forget to reference to the author's page), the interesting part will be the implementation of signal handlers for progress status.

Add one or multiple signal handlers to catch the `SIGUSR1` and `SIGINT`. Once a signal is catched, your program should dislay the current progress of the encoding or deconding tasks.

You will need the proper mechanisms for tracking the progress of any encoding/decoding task. You program must support plain text input files.

Encoding
--------
```
./base64 --encode input.txt
```
Your program should generate a new `encoded.txt` file with the result.

Decoding
--------
```
./base64 --decode encoded.txt
```
Your program will generate a `decoded.txt` file witg the result.

How to test?
------------
- Get process ID
```
ps aux | grep base64
```

- Send the signals
```
kill -SIGINT <PID>
kill -SIGINFO <PID>
```


Test files
----------
- [vgilante.txt](http://textfiles.com/stories/vgilante.txt)
- [sick-kid.txt](http://textfiles.com/stories/sick-kid.txt)
- [aesop11.txt](http://textfiles.com/stories/aesop11.txt)

**NOTE:** In case that your program is super fast, create a bigger file to make it take more time to process.
```
# This command will generate a ~1Gb bix.txt file
head -c 1073741824 </dev/urandom >big.txt
```

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [advanced-logger](https://github.com/CodersSquad/ap-labs/tree/master/labs/advanced-logger).
- `printf` function calls are not allowed, use your logger
- Use the `base64.c` file for implementing the lab's general flow.
- Use the `Makefile` for compilation.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.

How to submit your work and check your submission
=================================================
```
# Submit
GITHUB_USER=<your_github_user> make submit

# Check Submission
GITHUB_USER=<your_github_user> make check-submission
```

More details about Classify API : [Classify](../../classify.md)
