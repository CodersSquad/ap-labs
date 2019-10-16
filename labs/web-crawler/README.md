Lab - Depth-limiting Web Crawler
================================

Add depth-limiting to the concurrent web crawler from [crawl2.go](https://github.com/CodersSquad/hello-gophers/blob/master/src/crawl2.go).
That is, if the user sets `-depth=3`, then only URLs reachable by at most 3 links will be fetched.


General Requirements and Considerations
---------------------------------------
- Use the `crawl3.go` file for your implementation.
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

How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)
