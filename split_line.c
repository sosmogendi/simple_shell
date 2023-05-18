#include "shell.h"

/**
 * split_line - split a line into commands
 * @line: line to split
 *
 * Return: array of commands
 */

char **split_line(char *line)
{
	int buf_size = MAX_TOKENS;
	char **tokens2 = malloc(buf_size * sizeof(char *));
	char *token1;
	int token_index = 0;

	if (!tokens2)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}
	token1 = strtok(line, " ;");
	while (token1 != NULL)
	{
		tokens2[token_index] = token1;
		token_index++;
		if (token_index >= buf_size)
		{
			buf_size += MAX_TOKENS;
			tokens2 = realloc(tokens2, buf_size * sizeof(char *));
			if (!tokens2)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token1 = strtok(NULL, " ;");
	}
	tokens2[token_index] = NULL;
	return (tokens2);
}
