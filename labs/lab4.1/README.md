Lab 4.1 - Mutexes and Conditional Variables
===========================================

Mutexes
-------
1. Review, compile and run the `dotprod_serial.c` program. As its name implies, it is serial - no threads are created.
2. Now review, compile and run the `dotprod_mutex.c` program. This version of the dotprod program uses threads and requires a mutex to protect the global sum as each thread updates it with their partial sums.
3. Execute the `dotprod_mutex` program several times and notice that the order in which threads update the global sum varies.
4. Review, compile and run the `bug6.c` program.
5. Run it several times and notice what the global sum is each time? See if you can figure out why and fix it. An example solution is provided by the `bug6fix.c` program.
6. The `arrayloops.c` program is another example of using a mutex to protect updates to a global sum. Feel free to review, compile and run this example code as well.


Condition Variables
-------------------
1. Review, compile and run the `condvar.c` program. This example is essentially the same as the shown in the tutorial. Observe the output of the three threads.
2. Now, review, compile and run the `bug1.c` program. Observe the output of the five threads. What happens? See if you can determine why and fix the problem. An example solution is provided by the `bug1fix.c` program.
3. The `bug4.c` program is yet another example of what can go wrong when using condition variables. Review, compile (for gcc include the `-lm` flag) and run the code. Observe the output and then see if you can fix the problem. An example solution is provided by the `bug4fix.c` program.

General Requirements and Considerations
---------------------------------------
- Use the logger that was done on [lab2.4](https://github.com/CodersSquad/ap-labs/tree/master/labs/lab2.4).
- Replace all printing functions by the proper logger functions.
- Use the `*.c` files for implementing your code.
- Use the `Makefile` for compilation.
- Update `README.md` with the proper steps for building and running your code.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.


Submission Details
==================

Read [Classify API](../../classify.md)