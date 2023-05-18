#include "shell.h"

/**
 * my_setenv - Set the value of an environment variable
 * @variable: The variable name
 * @value: The variable value
 * Return: 0 on success, -1 on failure
 */
int my_setenv(const char *variable, const char *value)
{
	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Invalid no. of arguments\n");
		return (-1);
	}
	if (setenv(variable, value, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * my_unsetenv - Unset an environment variable
 * @variable: The variable name to unset
 * Return: 0 on success, -1 on failure
 */
int my_unsetenv(const char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "unsetenv: Invalid no. of argument\n");
		return (-1);
	}
	if (unsetenv(variable) == -1)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
