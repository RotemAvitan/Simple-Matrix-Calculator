
#define ROW 4
#define COL 4

#define BUFFER_MAX 150
#define MAX_PARAMAETERS 20
#define MATRICES_SIZE 6

#define FALSE 0
#define TRUE 1

void read_mat();
void print_mat();
void add_mat();
void sub_mat();
void mul_mat();
void mul_scalar();
void trans_mat();
void stop();

typedef struct mat {
  float data[ROW][COL];
} mat;

typedef struct matrix {
  char *name;
  mat *matrix;
} matrix;

typedef struct command_params {
  char *command;
  char *parameters[MAX_PARAMAETERS];
  int parameters_length;
} command_params;

typedef struct command {
  char *name;
  void (*func)(command_params *param);
  int min_arguments;
  int max_arguments;
} command;

matrix *get_matrix(char *name);
mat *get_matrix_data(matrix *matrix_var);
char *strstrip(char *s);
void print_matrix(mat *matrix_data);
void handleInput(char buffer[BUFFER_MAX]);
int min(int a, int b);
