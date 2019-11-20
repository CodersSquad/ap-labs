Lab - OpenMP
============

This is a single lab for multiple OpenMP exercises that we'll be doing in class. Below you can see the list of exercises that
will considered for the lab's grading. The goal of each exercise is to convert its default serial implementation to
a parallel implementation with OpenMP.

| Exercise Name          | Serial Implementation | Parallel Implementation                            |
|------------------------|-----------------------|----------------------------------------------------|
| Hello World            | `hello.c`             | `hello_par.c`                                      |
| Integral PI Compute    | `pi.c`                | `pi_spmd_simple.c`, `pi_spmd_final.c`, `pi_loop.c` |
| Monte Carlo PI Compute | `pi_mc.c`             | `pi_mc_par.c`                                      |
| Matrix Multiplication  | `matmul.c`            | `matmul_par.c`                                     |
| Producer/Consumer      | `prod_cons.c`         | `prod_cons_par.c`                                  |



Final Requirements and Considerations
---------------------------------------
- Use the logger that was done on [advanced-logger](https://github.com/CodersSquad/ap-labs/tree/master/labs/advanced-logger).
- Use the `*.c` files for implementing your code.
- Use the `Makefile` for compilation.
- Update `README.md` with the proper steps for building and running your code.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.


How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)
