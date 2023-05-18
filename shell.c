#include "shell.h"

/**
 * main - entry point into shell
 *
 * Return: 0
 */
int main(void)
{
    char input_line[MAX_INPUT_LINE];
    char **commands1;
    char **args;
    int condition;
    int exit_status = 0; /* Default exit status */
    int y;

    while (1) {
        /* Print prompt */
        printf("$ ");
        fflush(stdout);

        /* Read command line */
        if (fgets(input_line, MAX_INPUT_LINE, stdin) == NULL)
            break;
	/* Remove newline character */
        input_line[strcspn(input_line, "\n")] = '\0';
	 /* Split command line into commands */
        commands1 = split_line(input_line);

        /* Execute commands */
        for (y = 0; commands1[y] != NULL; y++) {
            /* Split command into arguments */
            args = split_line(commands1[y]);

            /* Execute command */
            if (args[0] != NULL) {
                if (strcmp(args[0], "exit") == 0) {
                    if (args[1] != NULL) {
                        exit_status = atoi(args[1]);
                    }
                    /* Free memory */
                    free(args);
                    free(commands1);
                    exit(exit_status);

                } else if (strcmp(args[0], "cd") == 0) {
                    /* Change directory */
                    if (args[1] != NULL) {
                        if (strcmp(args[1], "-") == 0) {
                            /* Handle "cd -" */
                            char *prev_dir = getenv("OLDPWD");
                            if (prev_dir != NULL) {
                                if (chdir(prev_dir) == -1)
                                    perror("chdir");
                            } else {
                                fprintf(stderr, "cd: OLDPWD not set\n");
                            }
                        } else {
                            if (chdir(args[1]) == -1) {
                                perror("chdir");
                            } else {
                                /* Update PWD environment variable */
                                char current_dir[MAX_INPUT_LINE];
                                if (getcwd(current_dir, sizeof(current_dir)) != NULL) {
                                    if (setenv("PWD", current_dir, 1) == -1) {
                                        fprintf(stderr, "cd: Failed to update PWD\n");
                                    }
                                } else {
                                    perror("getcwd");
                                }
                            }
                        }
                    } else {
                        /* Change to HOME directory if no argument is given */
                        char *home_dir = getenv("HOME");
                        if (home_dir != NULL) {
                            if (chdir(home_dir) == -1)
                                perror("chdir");
                        } else {
                            fprintf(stderr, "cd: HOME not set\n");
                        }
                    }
                } else if (strcmp(args[0], "env") == 0) {
                    /* Print the environment */
                    print_environment();
                } else if (strcmp(args[0], "setenv") == 0) {
                    /* Set environment variable */
                    if (args[1] != NULL && args[2] != NULL) {
                        if (setenv(args[1], args[2], 1) == -1) {
                            fprintf(stderr, "setenv: Failed to set environment variable\n");
                        }
                    } else {
                        fprintf(stderr, "setenv: Usage: setenv VARIABLE VALUE\n");
                    }
                } else if (strcmp(args[0], "unsetenv") == 0) {
                    /* Unset environment variable */
                    if (args[1] != NULL) {
                        if (unsetenv(args[1]) == -1) {
                            fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
                        }
                    } else {
                        fprintf(stderr, "unsetenv: Usage: unsetenv VARIABLE\n");
                    }
                } else {
                    /* Execute command */
                    condition = execute_command(args);
                    if (condition == -1) {
                        /* Command not found, try with PATH */
                        execute_command_path(args);
                    }
                }
            }

            /* Free memory */
            free(args);
        }

        /* Free memory */
        free(commands1);
    }

    /* Use exit_status as the argument for exit() */
    exit(exit_status);
    return (0);
}
