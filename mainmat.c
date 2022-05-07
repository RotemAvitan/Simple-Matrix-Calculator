/* Author: Rotem Avitan */

#include "mymat.h"

mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;

/* Initialize matrices with names */
matrix matrices[] = {{"MAT_A", &MAT_A}, {"MAT_B", &MAT_B}, {"MAT_C", &MAT_C},
                     {"MAT_D", &MAT_D}, {"MAT_E", &MAT_E}, {"MAT_F", &MAT_F}};

/* The main method that initialize the program */
int main() {
  char buffer[BUFFER_MAX] = {0};

  handleInput(buffer);
  return 0;
}
