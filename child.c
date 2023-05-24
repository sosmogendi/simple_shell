#include "shell.h"

/**
 * new_child - A function that creates a sub process.
 * @command: The pointer to tokenized command
 * @name: The pointer to the name of shell.
 * @env: The pointer to the enviromental variables.
 * @cicles: Number of executed cicles.
 * Return: Nothing.
 */
void new_child(char **command, char *name, char **env, int round)
{
	int pid = 0;
	int status = 0;
	int w_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (pid == 0)
	{
		execute(command, name, env, round);
		free_dp(command);
	}
	else
	{
		w_error = waitpid(pid, &status, 0);
		if (w_error < 0)
		{
			free_exit(command);
		}
		free_dp(command);
	}
}


/**
  * cd_dir - Afunction that changes working directory.
  * @path: The new current working directory.
  * Return: 0 on success, -1 on failure.
  */
int cd_dir(const char *path)
{
	char *buf2 = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf2, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
