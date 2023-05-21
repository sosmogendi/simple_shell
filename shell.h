#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;


#define MAX_TOKENS 64
#define TOKEN_DELIMITER " \t\r\n\a"
#define BUFFER_SIZE 1024
#define MAX_INPUT_LINE 1024
#define COMMAND_DELIMITER ";"


char **parse_command(char *command_line);
int execute_command(char **args);
void execute_command_path(char **args);
void print_environment(void);
char *my_getline(void);
int my_setenv(const char *variable, const char *value);
int my_unsetenv(const char *variable);
char **split_line(char *line);


#endif /* SHELL_H */

