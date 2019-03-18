Lab 3.1 - File/Directory Monitor
================================

Write a program that logs all file creations, deletions, and renames under the directory named in its command-line argument.
The program should monitor events in all of the subdirectories under the specified directory.
To obtain a list of all of these subdirectories, you will need to make use of [nftw()](https://linux.die.net/man/3/nftw).
When a new subdirectory is added under the tree or a directory is deleted, the set of monitored subdirectories should be updated accordingly.

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [lab2.4](https://github.com/CodersSquad/ap-labs/tree/master/labs/lab2.4).
- Use the `inotify` [API](http://man7.org/linux/man-pages/man7/inotify.7.html).
- Use the `monitor.c` file for implementing the lab's general flow.
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
{
    "message": "List of Users",
    "users": [
        {
            "GithubID": "obedmr",
            "ID": "ca83e551-5529-4fc0-971c-161f4f36516a",
            "Name": ""
        }
    ]
}
```

## Get lab ID
```
curl https://classify-234103.appspot.com/labs/\?shortName\=lab3.2
```
Expected sample output:
```
{
    "labs": [
        {
            "Description": "",
            "DueDate": "2019-03-27T05:59:39.848Z",
            "ID": "2fb40f0d-62ea-4b71-88b1-eee6ca18d60d",
            "Name": "Progress Notifier with Signals",
            "ShortName": "lab3.2"
        }
    ],
    "message": "List of Labs"
}
```

## Submit your lab
**Note:** Before submitting, make sure you do the common `git add`, `git commit` and `git push` for the new code changes in your `ap-labs` repository.
```
curl -k -X POST -d "commit=$(git rev-parse --short master)" https://classify-234103.appspot.com/labs/ca83e551-5529-4fc0-971c-161f4f36516a/2fb40f0d-62ea-4b71-88b1-eee6ca18d60c
```

Expected sample output:
```
{
    "commit": "7f961e9",
    "labID": "2fb40f0d-62ea-4b71-88b1-eee6ca18d60c",
    "message": "Submission Accepted",
    "submissionDate": "Sun Mar 17 22:56:34 2019",
    "userID": "ca83e551-5529-4fc0-971c-161f4f36516a"
}
```


## Check your Lab's submission
```
curl -k https://classify-234103.appspot.com/labs/ca83e551-5529-4fc0-971c-161f4f36516a/2fb40f0d-62ea-4b71-88b1-eee6ca18d60c
```

Expected sample output:
```
{
    "message": "Lab's submission data was successfully retrieved",
    "submission": {
        "CommitID": "7f961e9",
        "Date": "2019-03-18T04:56:34.523448Z",
        "ID": "61d04682-d130-4258-8141-5bc9a6e7b49c",
        "LabID": "2fb40f0d-62ea-4b71-88b1-eee6ca18d60c",
        "UserID": "ca83e551-5529-4fc0-971c-161f4f36516a"
    },
    "user": "ca83e551-5529-4fc0-971c-161f4f36516a"
}
```
