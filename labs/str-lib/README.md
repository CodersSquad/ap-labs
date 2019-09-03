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
./main originalVeryLongString Addition Add
Initial Lenght      : 22
New String          : originalVeryLongStringAddition
SubString was found : yes
```

General instructions
--------------------
1. Don't forget to do a `pull --rebase origin master` before anything.
2. Submit your code to your personal fork.
3. Use the  `strlib.c` and `main.c` files for your code.
4. Have fun and don't forget the [next section](#how-to-submit-your-work).


How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)