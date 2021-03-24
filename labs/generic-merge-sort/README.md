Lab - Generic Merge Sort
========================

On this lab you will be creating a [Merge
Sort](https://en.wikipedia.org/wiki/Merge_sort) based program for
sorting either strings or integers.

As a guide, take a look in the Quick Sort example from the [C
Programming
Language](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628)
book on **Section 5.11 - Pointers to Functions**.


How to run my program
---------------------

There are a couple of test files for your program
[`numbers.txt`](./numbers.txt) and
[`strings.txt`](./strings.txt). Your program will read the files and
then, perfom the sorting. Below you can see how your program should
support the 2 types of files.

your program will generate an output file with the `sorted_` prefix name.

- **Sort numbers (`numbers.txt`)**
```
# The `-n` is notifying the program that you're sorting a numbers file.
$ ./generic_merge_sort -n numbers.txt
Results file can be found at ./sorted_numbers.txt
```

- **Sort strings (`strings.txt`)**
```
$ ./generic_merge_sort strings.txt
Results file can be found at ./sorted_strings.txt
```


General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Push your code to your personal fork.
3. Use the  `generic_merge_sort.c` file for your code.
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
