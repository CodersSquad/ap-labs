Lab - Goroutines vs OS Threads
==============================
Read section 9.8 from The [Go Programming Language](https://www.amazon.com/dp/0134190440/ref=cm_sw_em_r_mt_dp_U_Uz0RDbHAH27PH) book.
Then, do the 9.4 and 9.5 exercises.

General Requirements and Considerations
---------------------------------------
- Develop your solutions in the `pipeline.go` (ex. 9.4) and `ping-pong.go` (ex. 9.5) files.
- Check `*.go` files to see how the output is expected.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.

Test Suite
----------
Build and Test automation is already implemented with the following command. Below some general tips and comments.

- Make sure that your program passes all test cases without errors.
- Remember that this is being executed by a robot script.
- You cannot edit the `lab.mk` file.
- Failed compilation or segmentation faults means 0-graded.
- Failed tests will be properly discounted from total grade.

```
make test
```


How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)
