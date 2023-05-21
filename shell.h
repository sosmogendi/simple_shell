#ifndef SHELL_H
#define SHELL_H

#include<shell.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<limits.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include <error.h>




char **parse_command(char *command_line);
int execute_command(char **args);
void execute_command_path(char **args);
void print_environment(void);
char *my_getline(void);
int my_setenv(const char *variable, const char *value);
int my_unsetenv(const char *variable);
char **split_line(char *line);

/*toem_getenv.c*/
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);


#endif /* SHELL_H */

