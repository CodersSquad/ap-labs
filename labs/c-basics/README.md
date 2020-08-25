Lab - C Basics
==============
Using basic concepts of C Programming from [C Basics lecture](http://talks.obedmr.com/hello-c-world/00-basics.slide#1),
create a program that calculates the conversion from Farenheit  to Celsius degrees.

Modify the provided `fahrenheit_celsius.c` file to receive the parameters in the following formats:

- Simple conversion
```
# ./fahrenheit_celsius <num_farenheit_degrees>
# Example:
./fahrenheit_celsius 0
Fahrenheit:   0, Celsius:  -17.8
```

- Range conversion
```
# ./fahrenheit_celsius <start> <end> <increment>
# Example:
./fahrenheit_celsius 0 100 20
Fahrenheit:   0, Celsius:  -17.8
Fahrenheit:  20, Celsius:   -6.7
Fahrenheit:  40, Celsius:    4.4
Fahrenheit:  60, Celsius:   15.6
Fahrenheit:  80, Celsius:   26.7
Fahrenheit: 100, Celsius:   37.8
```


General instructions
--------------------
1. Don't forget to sync first with the base [master](https://github.com/CodersSquad/ap-labs) branch.
2. Submit your code to your personal fork.
3. Use the  `fahrenheit_celsius.c` file for your code.
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