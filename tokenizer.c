#include "shell.h"

/**
 * tokenizes - splits and creates a full string command.
 * @s: delimiter for strtok.
 * @buffer: The pointer to input string.
 * Return: A string with full command.
 */
char **tokenizes(char *buffer, const char *s)
{
	char *token1 = NULL, **commands2 = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	commands2 = malloc((bufsize + 1) * sizeof(char *));
	if (commands2 == NULL)
	{
		perror("Not able to allocate buffer");
		free(buffer);
		free_dp(commands2);
		exit(EXIT_FAILURE);
	}

	token1 = strtok(buffer, s);
	while (token1 != NULL)
	{
		commands2[i] = malloc(_strlen(token1) + 1);
		if (commands2[i] == NULL)
		{
			perror("Not able to allocate buffer");
			free_dp(commands2);
			return (NULL);
		}
		_strcpy(commands2[i], token1);
		token1 = strtok(NULL, s);
		i++;
	}
	commands2[i] = NULL;
	return (commands2);
}
