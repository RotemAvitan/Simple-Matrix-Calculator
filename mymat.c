#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mymat.h"

void read_mat(command_params *param) {
  int i;
  int length = min((ROW * COL + 1), (*param).parameters_length);
  mat *matrix_a = get_matrix_data(get_matrix((*param).parameters[0]));

  if (matrix_a == NULL) {
    printf("Undefined matrix name\n");
    return;
  }
  for (i = 1; i < length; i++) {
    float value;
    int row, col;
    value = atof((*param).parameters[i]);

    row = (i - 1) / 4;
    col = (i - 1) % 4;
    if (value || strcmp((*param).parameters[i], "0") == 0) {
      (*matrix_a).data[row][col] = value;
    } else {
      printf("Argument is not a real number\n");
      return;
    }
  }

  print_matrix(matrix_a);
}

void print_mat(command_params *param) {
  mat *matrix_a = get_matrix_data(get_matrix((*param).parameters[0]));

  if (matrix_a == NULL) {
    printf("Undefined matrix name\n");
    return;
  }

  print_matrix(matrix_a);
}

void add_mat(command_params *param) {
  int i, j;

  mat *matrix_a = get_matrix_data(get_matrix((*param).parameters[0]));
  mat *matrix_b = get_matrix_data(get_matrix((*param).parameters[1]));
  mat *matrix_c = get_matrix_data(get_matrix((*param).parameters[2]));

  if (matrix_a == NULL || matrix_b == NULL || matrix_c == NULL) {
    printf("Undefined matrix name\n");
    return;
  }

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      (*matrix_c).data[i][j] = (*matrix_a).data[i][j] + (*matrix_b).data[i][j];
    }
  }

  print_matrix(matrix_c);
}

void sub_mat(command_params *param) {
  int i, j;

  mat *matrix_a = get_matrix_data(get_matrix((*param).parameters[0]));
  mat *matrix_b = get_matrix_data(get_matrix((*param).parameters[1]));
  mat *matrix_c = get_matrix_data(get_matrix((*param).parameters[2]));

  if (matrix_a == NULL || matrix_b == NULL || matrix_c == NULL) {
    printf("Undefined matrix name\n");
    return;
  }

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      (*matrix_c).data[i][j] = (*matrix_a).data[i][j] - (*matrix_b).data[i][j];
    }
  }

  print_matrix(matrix_c);
}

void mul_mat(command_params *param) {
  int i, j, k;

  mat *matrix_a = get_matrix_data(get_matrix((*param).parameters[0]));
  mat *matrix_b = get_matrix_data(get_matrix((*param).parameters[1]));
  mat *matrix_c = get_matrix_data(get_matrix((*param).parameters[2]));
  
  mat matrix_a_data = *matrix_a;
  mat matrix_b_data = *matrix_b;

  if (matrix_a == NULL || matrix_b == NULL || matrix_c == NULL) {
    printf("Undefined matrix name\n");
    return;
  }

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      for (k = 0; k < COL; k++) {
        (*matrix_c).data[i][j] += matrix_a_data.data[i][k] * matrix_b_data.data[k][j];
      }
    }
  }

  print_matrix(matrix_c);
}

void mul_scalar(command_params *param) {
  int i, j;
  float scalar;

  mat *matrix_a = get_matrix_data(get_matrix((*param).parameters[0]));
  mat *matrix_c = get_matrix_data(get_matrix((*param).parameters[2]));
  
  mat matrix_a_data = *matrix_a;

  if (matrix_a == NULL || matrix_c == NULL) {
    printf("Undefined matrix name\n");
    return;
  }

  scalar = atof((*param).parameters[1]);

  if (scalar || strcmp((*param).parameters[1], "0") == 0) {
    for (i = 0; i < ROW; i++) {
      for (j = 0; j < COL; j++) {
        (*matrix_c).data[i][j] = matrix_a_data.data[i][j] * scalar;
      }
    }
  } else {
    printf("Argument is not a scalar\n");
    return;
  }

  print_matrix(matrix_c);
}

void trans_mat(command_params *param) {
  int i, j;

  mat *matrix_a = get_matrix_data(get_matrix((*param).parameters[0]));
  mat *matrix_c = get_matrix_data(get_matrix((*param).parameters[1]));
  
  mat matrix_a_data = *matrix_a;

  if (matrix_a == NULL || matrix_c == NULL) {
    printf("Undefined matrix name\n");
    return;
  }

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      (*matrix_c).data[i][j] = matrix_a_data.data[j][i];
    }
  }

  print_matrix(matrix_c);
}

void stop() { exit(0); }
