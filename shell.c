#include "shell.h"

/**
 * main - entry point into shell
 *
 * Return: 0
 */

int main(void)
{
	char input_line[MAX_INPUT_LINE];
	char **args2;
	int condition;

	while (1)
	{
	/* Print prompt */
	printf("$ ");
	fflush(stdout);

	/* Read command */
	if (fgets(input_line, MAX_INPUT_LINE, stdin) == NULL)
		break;

	/* Remove newline character */
	input_line[strcspn(input_line, "\n")] = '\0';

	/* Split command into arguments */
	args2 = split_line(input_line);
	/* Execute command */
	if (args2[0] != NULL)
	{
	if (strcmp(args2[0], "exit") == 0)
	{
		/* Exit the shell */
		break;
	}
	else if
	(strcmp(args2[0], "cd") == 0)
	{
	/* Change directory */
	if (args2[1] != NULL)
	{
		if (chdir(args2[1]) == -1)
			perror("chdir");
	}
	else
	{
	fprintf(stderr, "cd:There is a missing argument\n");
	}
	}
	else
	{
	/* Execute command */
	condition = execute_command(args2);
	if (condition == -1)
	{
	/* Command not found, try with PATH */
	execute_command_path(args2);
	}
	}
	}
	/* Free memory */
	free(args2);
	}
	return (0);
}
