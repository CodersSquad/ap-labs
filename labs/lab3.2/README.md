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

## Get your Classify API ID
```
curl -k https://classify-234103.appspot.com/users/\?githubID\=obedmr
```
Expected sample output:
```
{"message":"List of Users","users":[{"ID":"ca83e551-5529-4fc0-971c-161f4f36516a","Name":"","GithubID":"obedmr"}]}
```

## Get lab ID
```
curl https://classify-234103.appspot.com/labs/\?shortName\=lab3.2
```
Expected sample output:
```
{"labs":[{"ID":"2fb40f0d-62ea-4b71-88b1-eee6ca18d60d","Name":"Progress Notifier with Signals","ShortName":"lab3.2","Description":"","DueDate":"2019-03-27T05:59:39.848Z"}],"message":"List of Labs"}
```

## Submit your lab
**Note:** Before submitting, make sure you do the common `git add`, `git commit` and `git push` for the new code changes in your `ap-labs` repository.
```
curl -k -X POST -d "commit=$(git rev-parse --short master)" https://classify-234103.appspot.com/labs/ca83e551-5529-4fc0-971c-161f4f36516a/2fb40f0d-62ea-4b71-88b1-eee6ca18d60d
```

Expected sample output:
```
{"commit":"7f961e9","labID":"2fb40f0d-62ea-4b71-88b1-eee6ca18d60d","message":"Submission Accepted","submissionDate":"Sat Mar 16 23:56:02 2019","userID":"ca83e551-5529-4fc0-971c-161f4f36516a"}
```


## Check your Lab's submission
```
curl -k https://classify-234103.appspot.com/labs/ca83e551-5529-4fc0-971c-161f4f36516a/2fb40f0d-62ea-4b71-88b1-eee6ca18d60d
```

Expected sample output:
```
{"message":"Lab's submission data was successfully retrieved","submission":{"ID":"7fd63e1d-b685-44a0-9b0d-ff7d32e1e25d","UserID":"ca83e551-5529-4fc0-971c-161f4f36516a","LabID":"2fb40f0d-62ea-4b71-88b1-eee6ca18d60d","CommitID":"7f961e9","Date":"2019-03-17T05:56:02.416757Z"},"user":"ca83e551-5529-4fc0-971c-161f4f36516a"}
```
