#include "shell.h"

/**
 * free_dp - frees all the memory allocated for command.
 * @command: pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_dp(char **command)
{
	size_t e = 0;

	if (command == NULL)
		return;

	while (command[e])
	{
		free(command[e]);
		e++;
	}

	if (command[e] == NULL)
		free(command[e]);
	free(command);
}


/**
 * free_exit - frees all the memory allocated and exit.
 * @command: pointer to allocated command memory to free.
 * Return: Nothing.
 */
void free_exit(char **command)
{
	size_t m = 0;

	if (command == NULL)
		return;

	while (command[m])
	{
		free(command[m]);
		m++;
	}

	if (command[m] == NULL)
		free(command[m]);
	free(command);
	exit(EXIT_FAILURE);
}
