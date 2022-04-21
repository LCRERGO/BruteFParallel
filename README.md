# BruteFParallel
----------------
This repository is made to aggregate the code for the final task of Parallel
and Distrubuted Programming Discipline of UFSCar.

This task requires to improve the performance of a Brute Force algorithm using
OpenMP, MPI and CUDA.

## Dependencies

To build and run it is required to have openssl libraries, in Debian based distros it can
be acomplished with:

```bash
# apt-get install libssl-dev
```

It is also needed to have a compiler toolchain such as gcc, which can be
acomplished on Debian based distros with:

```bash
# apt-get install build-essential
```

## Building
To build the program simply run make and then a password\_bf executable should
be generated on the directory.

```bash
$ make
```
