Lab - Matrix Multiplication
===========================
On this lab you will create a multi-threaded matrix multiplicator with the usage of the `pthreads` library. You will see the following concurrent programming concepts:

- Multithreading
- Synchronization mechanisms
- Race conditions


General instructions
--------------------

1. Use the  `multiplier.c` file for your code
2. Your program should be able to receive one argument (`-n`) which will be know as `NUM_BUFFERS` inside the program
3. An output argument (`-out`) will be required for the `RESULT_MATRIX_FILE`.
3. You will read a couple of files (`matA.dat`, `matB.dat`) which contain data that will be used for the matrices multiplication. It's an array that represents all matrix's rows in an one-dimension array.
4. Below some functions that will be required:
   - `long * readMatrix(char *filename)`
     Reads matrix file and returns an long type array with content of matrix.
   - `long * getColumn(int col, long *matrix)`
     Returns the specified array that represents a column in the matrix array.
   - `long * getRow(int row, long *matrix)`
     Returns the specified array that represents a row in the matrix array.
   - `int getLock()`
     Search for an available buffer, if so it returns the available lock id which is the same buffer id, otherwise returns -1
   - `int releaseLock(int lock)`
     Releases a buffer and unlock the mutex. Returns 0 for successful unlock, otherwise -1.
   - `long dotProduct(long *vec1, long *vec2)`
     Given 2 arrays of 2000 lenght, it calculates the dot product and returns it as a long type value.
   - `long * multiply(long *matA, long *matB)`
     Here's where all the magic happens. Explained in [Matrix multiplication section](#matrix-multiplication)
   - `int saveResultMatrix(long *result)`
     Saves result matrix into a new `RESULT_MATRIX_FILE` file, return 0 for a successful operation, otherwise it will return -1
   - Your program will be executed as follows:

```
./multiplier -n 10 -out result.txt
```

Some key required global variables
----------------------------------

- `NUM_BUFFERS`
  Number of temporal buffers for vectors that will be used for each dot product.
- `long **buffers`
  An array of `NUM_BUFFERS` pointers to the available buffers that will serve as temporal vectors for dot product operations.
- `pthread_mutex_t *mutexes`
  Mutexes that will help to know which buffer is available
- `long * result`
  Will store the result of `matA` and `matB` multiplication


Matrix multiplication
---------------------

- You will have a loop that is creating NxN (2000*2000) threads in lots of 2000 concurrent processes for calculating the `row*col` operations between `matA` and `matB`.
- The idea of having 2000 concurrent processes is to play with the synchronization of the "limited" memory you have with the defined number of buffers (`NUM_BUFFERS`).
- Each thread will execute `row*col` operation and will use available 2 buffers for temporaly storing the 2 arrays that are required for calculating the dot product.
`getLock` function will be required to get a buffer for storing a vector, if there's no available buffer, thread will need to wait.
`releaseLock` will be used to release a buffer to be used by another thread.
- At the end, you'll wait for all processes to join the main execution.
- Each lot of 2000 threads goal will represent a row in the final matrices multiplication result.
- Finally, save your result by calling the `saveResultMatrix` function.


Data files
----------
`matA.dat` and `matB.dat` are located at:
- [Classify Share](https://console.cloud.google.com/storage/browser/classify-share)

Below you can see how data can be read/interpreted:

```
# Data File                 # Matrix Representation
1                           1   2   3
2                           4   5   6
3                           7   8   9
4
5
6
7
8
9
```

**Note:** `RESULT_MATRIX_FILE` file must be saved on similar format as shown above.




Final Requirements and Considerations
---------------------------------------
- Use the logger that was done on [advanced-logger](https://github.com/CodersSquad/ap-labs/tree/master/labs/advanced-logger).
- `printf` function calls are not allowed, use your logger.
- Use the `*.c` files for implementing your code.
- Use the `Makefile` for compilation.
- Update `README.md` with the proper steps for building and running your code.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.


Test Suite
----------
Build and Test automation is already implemented with the following command. Below some general tips and comments.

- Make sure that your program passes all test cases without errors.
- Remember that this is being executed by a robot script.
- You cannot edit the `lab.mk` file.
- Failed compilation or segmentation faults means 0-graded.
- Failed tests without proper handling  will be properly discounted from total grade.

```
make test
```

How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)
