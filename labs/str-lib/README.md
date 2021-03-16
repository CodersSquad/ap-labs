Lab - String Manipulation Library
=================================

- Implement a library for string manipulation library with the following functions:
```
int mystrlen(char *str)
char *mystradd(char *origin, char *addition)
int mystrfind(char *origin, char *substr)
```

- Call all functions on `strlib.c` from the `main.c` file

- Your program needs to support the following arguments. Check the following examples for expected output:
```
$ ./main.o -add "Initial String " "This is the rest to be added"
Initial Lenght      : 15
New String          : Initial String This is the rest to be added
New length          : 43

$ ./main.o -find "Initial String " "Init"
['Init'] string was found at [0] position
```

General instructions and advices
--------------------------------
0. Take a look on [Linking Process in C](http://talks.obedmr.com/hello-c-world/03-linking.slide#1) for a better undersanding.
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Push your code to your personal fork.
3. Use the  `strlib.c` and `static-linking.c` files for your code.
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
make submit
```
More details at: [Classify API](../../classify.md)
