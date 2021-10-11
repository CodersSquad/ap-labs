Lab - Generic Sort
==================

On this lab you will be creating a generic sort solution that will be
able to sort either numbers or strings. Your program will also support
2 types of sorting algorithms:

- [MergeSort](https://en.wikipedia.org/wiki/Merge_sort)
- [QuickSort](https://en.wikipedia.org/wiki/Quicksort)

The objective of this exercise is to practice pointers and also
experiment with pointers to functions. You will need to modify the
provided `*.c` files in order to add support for both sorting
algorithms (quicksort and mergesort).

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

- **Sort numbers (`numbers.txt`)**
  - The `-n` is notifying the program that you're sorting a numbers file
  - The `-quicksort` argument indicates which sorting algorithm will be used
  - The `-o` argument provides the output file
```
$ ./genericsort -n numbers.txt -quicksort -o qs_sorted_numbers.txt
... sorting numbers.txt file with quicksort
... Results file can be found at ./qs_sorted_numbers.txt
```

- **Sort strings (`strings.txt`)**
  - If no `-n`, it means it will see the input file as strings file
  - The `-mergesort` argument indicates which sorting algorithm will be used
  - The `-o` argument provides the output file
```
$ ./genericsort strings.txt -mergesort -o ms_sorted_strings.txt
... sorting strings.txt file with mergesort
... Results file can be found at ./ms_sorted_strings.txt
```


General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Push your code to your personal fork.
3. You can only edit the `genericsort.c`, `quicksort.c` and `mergesort.c` files
4. Don't modify the `mergesort` and `quicksort` functions parameters
5. Have fun and don't forget the following section.

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
