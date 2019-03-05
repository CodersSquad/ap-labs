Lab 2.5 - Depth-limiting Web Crawler
====================================

Add depth-limiting to the concurrent web crawler from [crawl2.go](https://github.com/CodersSquad/hello-gophers/blob/master/src/crawl2.go).
That is, if the user sets `-depth=3`, then only URLs reachable by at most 3 links will be fetched.


General Requirements and Considerations
---------------------------------------
- Use the `crawl3.go` file for your implementation.
- Update `README.md` with the proper steps for building and running your code.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.


Test Cases
==========
Your program will be tested with the following URLs:

```
# Test 1
go run crawl3.go -depth=2 https://google.com/

# Test 2
go run crawl3.go -depth=3 http://www.gopl.io/

# Test 3
go run crawl3.go -depth=1  http://www.gopl.io/

```

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
curl -k -X POST -d "commit=$(git rev-parse --short master)" https://classify-232805.appspot.com/labs/obedmr/lab2.5
```

Expected sample output:
```
{"commit":"755667f","dueDate":"Tue Mar 12 23:59:00 2019","labID":"lab2.5","message":"Submission Accepted","submissionDate":"Mon Mar  4 21:45:29 2019","user":"obedmr"}
```


## Check your Lab's submission
```
curl -k https://classify-232805.appspot.com/labs/obedmr/lab2.5
```

Expected sample output:
```
{"message":"Lab's submission data was successfully retrieved","submission":{"ID":"obedmr.lab2.5","LabID":"lab2.5","CommitID":"755667f","Date":"2019-03-05T03:45:29.500133921Z"},"user":"obedmr"}
```
