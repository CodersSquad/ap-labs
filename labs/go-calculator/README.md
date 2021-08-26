Lab - Basic Calculator in Golang
================================
This is a basic calculator that receives an operator (add, sub or
mult) and then a serie of numbers that will be proccessed with the
selected operator.

Make the proper changes in the `calculator.go` file in order to support
**command line arguments** and to **handle errors** in case of non supported
operators or invalid numbers. For this exercise we're only using
integer numbers. You are free to create helper functions but you're
not allowed to change the `calc` function's signature (arguments and
return type).

Your program must support dynamic number of values. In case of wrong
arguments, you must print the error message, otherwise it will not
count in the final lab's grade.


Your program should be executed as follows:

```
./calculator <operator> <numbers separated by space>
```

Below you can see 3 sample executions for each operator that your
program will support:


- Addition
```
./calculator add 1 2 3 4 5
1 + 2 + 3 + 4 + 5 = 15
```

- Subtraction
```
./calculator sub 1 2 3 4 5
1 - 2 - 3 - 4 - 5 = -13
```

- Multiplication
```
./calculator mult 1 2 3 4 5
1 * 2 * 3 * 4 * 5 = 120
```



General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Push your code to your personal fork.
3. Use the  `calculator.go` file for your code.
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
More details at: [Classify API](../../classify.md#submit-a-lab-to-classify)