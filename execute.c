#include "shell.h"

/**
 * execute - executes a command.
 * @command: pointer to tokienized command
 * @name: name of the shell.
 * @env: The pointer to the enviromental variables.
 * @round3: Number of executed cicles.
 * Return: Nothing.
 */
void execute(char **command, char *name, char **env, int round3)
{
	char **paths2 = NULL, *full_path1 = NULL;
	struct stat st;
	unsigned int x = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
		}
	}
	else
	{
		paths2 = get_PATH(env);
		while (paths2[x])
		{
			full_path1 = _strcat(paths2[x], command[0]);
			x++;
			if (stat(full_path1, &st) == 0)
			{
				if (execve(full_path1, command, env) < 0)
				{
					perror(name);
					free_dp(paths2);
					free_exit(command);
				}
				return;
			}
		}
		msgerror(name, round3, command);
		free_dp(paths2);
	}
}


/**
 * print_env -  prints all enviromental variables.
 * @env: pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t k = 0, len1 = 0;

	while (env[k])
	{
		len1 = _strlen(env[k]);
		write(STDOUT_FILENO, env[k], len1);
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}
}


/**
 * get_PATH - function to gets the full value from.
 * enviromental variable PATH.
 * @env: The pointer to enviromental variables.
 * Return: All tokenized pathways for commands.
 */
char **get_PATH(char **env)
{
	char *path_value = NULL, **paths2 = NULL;
	unsigned int i = 0;

	path_value = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(path_value, "PATH"))
		{
			path_value = strtok(NULL, "\n");
			paths2 = tokenizes(path_value, ":");
			return (paths2);
		}
		i++;
		path_value = strtok(env[i], "=");
	}
	return (NULL);
}


/**
 * msgerror - prints message not found.
 * @name: name of the shell.
 * @round4: Number of cicles.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void msgerror(char *name, int round4, char **command)
{
	char s;

	s = round4 + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
