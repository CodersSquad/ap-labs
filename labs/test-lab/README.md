test-lab
========

This is a test lab that will help on the process of submitting your first lab to the Classify API.


Hello World in Go
-----------------

Modify the `test-lab.go` in order to support a personalized hello message. Below a sample execution.

```
$ go run test-lab.go Obed
Hello Obed, Welcome to the Jungle
```

Below some extra requirements to be considered:
- The program must support single (one word) and full (muliple words) names.
- In case that no name is sent, the program must send an error message


General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/dc-labs) branch.
2. Push your code to your personal fork.
3. Use the  `test-lab.go` file for your code.
4. Have fun and don't forget to submit your work.

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
make submit
```
More details at: [Classify API](../../classify.md)