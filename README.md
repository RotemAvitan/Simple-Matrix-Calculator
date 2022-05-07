# Simple Matrix Calculator

This program handles matrix simple calculations like add, subtract, multiplication, and more.

## How to build

See `Makefile` for the build scripts.

To build the command line example, simply run `make`
at the command line in the current directory.

By default, this will generate an executable called `matrix_calculator`
is bound to in `Makefile`

## Features

* Matrix Addition
* Matrix Subtraction
* Matrix Multiplication
* Matrix Transpose
* Matrix Multiplication
* Matrix Scalar Multiplication

## Commands
* `read_mat <matrix_a>, <values>` - invoke values into matrix_a, the values must be seperated by commas(',')
* `print_mat <matrix_a>` - print the matrix values with nice and simple display
* `add_mat <matrix_a>, <matrix_b>, <matrix_c>` - addition matrix_a and matrix_b values and store them in matrix_c
* `sub_mat <matrix_a>, <matrix_b>, <matrix_c>` - subtract matrix_b from matrix_a values and store them in matrix_c
* `mul_mat <matrix_a>, <matrix_b>, <matrix_c>` - multiply matrix_a and matrix_b values and store them in matrix_c
* `scalar_mul <matrix_a>, <scalar>, <matrix_b>` - multiply matrix_a by scalar (float number) value and store the values them in matrix_b
* `trans_mat <matrix_a>, <matrix_b>` - transpose matrix <matrix_a> and store it's value in matrix_b
* `stop` - stops the program

The file `input.txt` has run examples in order to show the program's capabilities.
