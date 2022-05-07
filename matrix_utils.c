#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "mymat.h"

extern matrix matrices[MATRICES_SIZE];

/* Get the matrix */
matrix *get_matrix(char *name) {
  int i;

  for (i = 0; i < MATRICES_SIZE; i++) {
    if (strcmp(name, matrices[i].name) == 0) {
      return &matrices[i];
    }
  }

  return NULL;
}

/* Get the matrix data from the matrix */
mat *get_matrix_data(matrix *matrix_var) {
  return matrix_var == NULL? NULL : (*matrix_var).matrix;
}

void print_matrix(mat *matrix_data) {
  int i, j;
  
  printf("-----------------------------\n");
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      printf("%.2f \t", (*matrix_data).data[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------------\n");
}

/* Strip string prefix and suffix */
char *strstrip(char *s) {
    size_t size;
    char *end;
    
    size = strlen(s);

    if (!size)
        return s;

    end = s + size - 1;
    while (end >= s && isspace(*end))
        end--;
    *(end + 1) = '\0';

    while (*s && isspace(*s))
        s++;

    return s;
}

int min(int a, int b) { return (a > b) ? b : a; }
