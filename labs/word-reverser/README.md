Lab - Word Reverser
===================
Using basic concepts of C Programming from [C Basics lecture](http://talks.obedmr.com/hello-c-world/00-basics.slide#1),
create a program that reads input from console with `getchar()` function.

Every word will be automatically reversed and printed when the `enter` key is pressed.

The condition to stop your program will be the `EOF` char, also triggered by `Cntrl-D`.


General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Submit your code to your personal fork.
3. Use the  `reverser.c` file for your code.
4. Have fun and don't forget the next section.


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