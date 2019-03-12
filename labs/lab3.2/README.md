Lab 3.2 - Progress Notifier with Signals
========================================
Implement a program for encoding and decoding files by using the `Base64` [algorithm](https://en.wikibooks.org/wiki/Algorithm_Implementation/Miscellaneous/Base64).
You're free to copy from  previous link's implementation (don't forget to reference to the author's page), the interesting part will be the implementation of signal handlers for progress status.

Add one or multiple signal handlers to catch the `SIGINFO` and `SIGINT`. Once a signal is catched, your program should dislay the current progress of the encoding or deconding tasks.

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

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [lab2.4](https://github.com/CodersSquad/ap-labs/tree/master/labs/lab2.4).
- Use the `base64.c` file for implementing the lab's general flow.
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
Expected sample output:
```
{"message":"Welcome obedmr","user":"obedmr"}
```


## Submit your lab
**Note:** Before submitting, make sure you do the common `git add`, `git commit` and `git push` for the new code changes in your `ap-labs` repository.
```
curl -k -X POST -d "commit=$(git rev-parse --short master)" https://classify-232805.appspot.com/labs/obedmr/lab3.2
```

Expected sample output:
```
{"commit":"755667f","dueDate":"Tue Mar 12 23:59:00 2019","labID":"lab3.2","message":"Submission Accepted","submissionDate":"Mon Mar  4 21:45:29 2019","user":"obedmr"}
```


## Check your Lab's submission
```
curl -k https://classify-232805.appspot.com/labs/obedmr/lab3.2
```

Expected sample output:
```
{"message":"Lab's submission data was successfully retrieved","submission":{"ID":"obedmr.lab3.2","LabID":"lab3.2","CommitID":"755667f","Date":"2019-03-05T03:45:29.500133921Z"},"user":"obedmr"}
```
