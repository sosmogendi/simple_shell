#include "shell.h"

/**
 * split_line - split a line into tokens
 * @line: line to split
 *
 * Return: array of tokens
 */
char **split_line(char *line)
{
	char **tokens2 = malloc(MAX_ARGS * sizeof(char *));
	char *token1;
	int n = 0;

	if (!tokens2)
	{
		perror("Allocation Error");
		exit(EXIT_FAILURE);
	}
	token1 = strtok(line, " \t\r\n\a");
	while (token1 != NULL)
	{
		tokens2[n] = strdup(token1);
		if (!tokens2[n])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		n++;
		token1 = strtok(NULL, " \t\r\n\a");
	}
	tokens2[n] = NULL;
	return (tokens2);
}
