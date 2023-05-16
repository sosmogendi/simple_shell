#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_INPUT_LINE 1024
#define MAX_ARGS 64

char **parse_command(char *command_line);
char **split_line(char *line);
int execute_command(char **args);
void execute_command_path(char **args);
void print_environment(void);


#endif /* SHELL_H */
