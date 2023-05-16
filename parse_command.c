#include "shell.h"

/**
 * parse_command - Parse a command line into an array of arguments
 * @command_line: The command line to parse
 *
 * Return: An array of strings, where each string is an argument
 */
char **parse_command(char *command_line)
{
	char **args = NULL;
	char *token1 = NULL;
	int x = 0;

	/* Split command_line into tokens using space as a delimiter */
	token1 = strtok(command_line, " ");
	while (token1 != NULL)
	{
		/* Allocate memory for the new argument */
		args = realloc(args, (x + 1) * sizeof(char *));
		if (args == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		/* Copy the token into the new argument */
		args[x] = strdup(token1);
		if (args[x] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		/* Get the next token */
		token1 = strtok(NULL, " ");
		x++;
	}
	/* Add a NULL terminator to the end of the argument list */
	args = realloc(args, (x + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	args[x] = NULL;
	return (args);
}
