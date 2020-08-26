Lab - Month Day Calculator
===========================
Using basic concepts of [Pointers and Structures lecture](http://talks.obedmr.com/hello-c-world/01-pointers-structures.slide#8),
create a program that calculates the month's day from a given year and year's day. Use pointers for the month and month's day variables.
Don't forget to add proper errors handling in your program.

Modify the provided `month_day.c` file to receive the parameters in the way and also print the proper formatted output.

```
# ./month_day <year> <yearday>
# Example for Feb 2nd, 2019:
./month_day 2019 33
Feb 02, 2019
```


General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Push your code to your personal fork.
3. Use the  `month_day.c` file for your code.
4. Have fun and don't forget the following section.


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