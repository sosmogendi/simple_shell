#include "shell.h"

/**
 * tokenize - tokenizes a buffer with a delimiter
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenize(char *buffer, char *delimiter)
{
	char **tokens2 = NULL;
	size_t i = 0,  tally = 10;

	if (buffer == NULL)
		return (NULL);
	tokens2 = malloc(sizeof(char *) * tally);
	if (tokens2 == NULL)
	{
		perror("Error");
		return (NULL);
	}
	while ((tokens2[i] = new_strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == tally)
		{
			tokens2 = _realloc(tokens2, &tally);
			if (tokens2 == NULL)
			{
				perror("Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens2);
}
