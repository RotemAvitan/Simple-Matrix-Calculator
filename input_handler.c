#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mymat.h"

#define SPACE_STR " "
#define COMMA_STR ","
#define COMMA_CHAR ','

int inject_parameters(command_params *parameters, char *token, char command[BUFFER_MAX]);
void command_execution(command_params *parameters, char command_string[BUFFER_MAX]);

/* Register command with function name. minimum arguments and maximum arguments */
static command cmd[] = {{"read_mat", read_mat, 2, 100}, {"print_mat", print_mat, 1, 1},
                        {"add_mat", add_mat, 3, 3},     {"sub_mat", sub_mat, 3, 3},
                        {"mul_mat", mul_mat, 3, 3},     {"mul_scalar", mul_scalar, 3, 3},
                        {"trans_mat", trans_mat, 2, 2}, {"stop", stop, 0, 0}};

/* Handle all the user's input and forward it to the functions that handle the commands */
void handleInput(char buffer[BUFFER_MAX]) {
  int valid;
  
  /* Loop while there's input */
  while (fgets(buffer, BUFFER_MAX, stdin) != NULL) {
    command_params parameters;
    char command[BUFFER_MAX];
    char *buffer_paramaters;
    char *token;

    buffer[strcspn(buffer, "\n")] = 0;
    
    puts(buffer);
    
    if (buffer[strlen(buffer)-1] == COMMA_CHAR) {
      printf("Extraneous text after end of command\n");
      continue;
    }
    strcpy(command, buffer);
    token = strtok(command, SPACE_STR);
    
    /* Check for extra spaces between arguments instead of comma */
    if (command[strlen(command)-1] == COMMA_CHAR) {
      printf("Illegal comma\n");
      continue;
    }
    
    buffer_paramaters = buffer + strlen(command) + 1;
    token = strtok(buffer_paramaters, COMMA_STR);

    valid = inject_parameters(&parameters, token, command);
    
    /* Check if the parameters entered correctly adn execute the command */
    if (valid) {
      command_execution(&parameters, command);
    }
  }
}

int inject_parameters(command_params *parameters, char *token, char command[BUFFER_MAX]) {
  int parameter_index;
  
  /* Loop throught arguments, normalize data and validation */
  for (parameter_index = 0; (token != NULL && parameter_index <= MAX_PARAMAETERS); parameter_index++) {
    token = strstrip(token);
    if (strcmp(token, "") == 0) {
      printf("Multiple consecutive commas\n");
      return FALSE;
    }
    
    if (strchr(token, ' ') != NULL) {
      printf("Missing comma\n");
      return FALSE;
    }
    
    (*parameters).parameters[parameter_index] = token;
    token = strtok(NULL, COMMA_STR);
  }

  (*parameters).command = command;
  (*parameters).parameters_length = parameter_index;
  
  return TRUE;
}

void command_execution(command_params *parameters, char command_string[BUFFER_MAX]) {
  int i;
  int parameters_length = (*parameters).parameters_length;

  for (i = 0; cmd[i].func != NULL; i++) {
    if (strcmp(command_string, cmd[i].name) == 0) {
      break;
    }
  }

  if (cmd[i].func == NULL) {
    printf("Undefined command name\n");
  } else {
    command com = cmd[i];

    if (com.min_arguments > parameters_length) {
      printf("Missing argument\n");
      return;
    }

    if (com.max_arguments < parameters_length) {
      printf("Extraneous text after end of command\n");
      return;
    }
    
    /* Invoke the matching function with the command's parameters */
    (*(cmd[i].func))(parameters);
  }
}

