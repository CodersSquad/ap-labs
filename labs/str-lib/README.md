Lab - String Manipulation Library
=================================

- Implement a library for string manipulation library with the following functions:
```
int mystrlen(char *str)
char *mystradd(char *origin, char *addition)
int mystrfind(char *origin, char *substr)
```

- Call all functions on `strlib.c` from the `main.c` file

- Your program needs to support the following arguments. Check the expected output:
```
$ ./main originalVeryLongString Addition Add
Initial Lenght      : 22
New String          : originalVeryLongStringAddition
SubString was found : yes
```

General instructions and advices
--------------------------------
0. Take a look on [Linking Process in C](http://talks.obedmr.com/hello-c-world/03-linking.slide#1) for a better undersanding.
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Push your code to your personal fork.
3. Use the  `strlib.c` and `main.c` files for your code.
4. Have fun and don't forget the following section.


How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)