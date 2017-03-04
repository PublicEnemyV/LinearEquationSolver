# LinearEquationSolver

The program can solve linear system equations, using the measures discussed from the book *Numerical Analysis*.

Note: We can only solve full-ranked linear system equations. Please make sure your input matrix full ranked!

## Build

To build the program,

`make`

To clean the directory,

`make clean`

Note: The makefile is written for Windows, for other OS, please edit the makefile manually.

## Example Usage

An example usage is provided in the `main.cpp`, you can change the solving method by changing the parameter on **Line 44, main.cpp**.

A possible method could be

+ GaussianElimination
+ PCAGaussianElimination
+ SequentialGaussianElimination

The first one is recommended in order to prevent potential error.
