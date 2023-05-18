#include "shell.h"

/**
 * print_environment - print the current environment
 */
void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * execute_command - execute command with arguments
 * @args: array of command line arguments
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args)
{
	pid_t pid;
	int condition;

	if (strcmp(args[0], "exit") == 0)
	{
	exit(0); /* Exit the shell*/
	}
	else
	{
	pid = fork();
	if (pid == -1)
	{
	perror("fork");
	return (-1);
	}
	else if (pid == 0)
	{
	/* Child process */
	if (execvp(args[0], args) == -1)
	{
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	}
	else
	{
	/* Parent process */
	do {
	if (waitpid(pid, &condition, WUNTRACED) == -1)
	{
	perror("waitpid");
	return (-1);
	}
	} while (!WIFEXITED(condition) && !WIFSIGNALED(condition));
	}
	}
	return (0);
}

/**
 * execute_command_path - execute command with
 * arguments using the PATH variable
 * @args: array of command line arguments
 */


void execute_command_path(char **args)
{
	char *command1 = args[0];
	char *path_envit = getenv("PATH");
	char *path = path_envit;
	char *full_path1;
	int command1_len = strlen(command1);
	int path_len;
	char buf[BUFFER_SIZE];  /* Buffer to store the path segment */

	while (*path != '\0')
	{
	path_len = 0;
	while (path[path_len] != '\0' && path[path_len] != ':')
	{
	buf[path_len] = path[path_len];
	path_len++;
	}
	buf[path_len] = '\0';

	/* Construct full path */
	full_path1 = malloc((path_len + command1_len + 2) * sizeof(char));
	if (full_path1 == NULL)
	{
	perror("malloc");
	exit(EXIT_FAILURE);
	}
	strcpy(full_path1, buf);
	full_path1[path_len] = '/';
	strcpy(full_path1 + path_len + 1, command1);

	/* Check if file exists and is executable */
	if (access(full_path1, X_OK) == 0)
	{
	/* Execute command */
	args[0] = full_path1;
	execute_command(args);
	free(full_path1);
	return;
	}
	free(full_path1);
	/* Move to the next path */
	if (path[path_len] == ':')
		path += path_len + 1;
	else
		break;
	}
	/* Command not found */
	fprintf(stderr, "Command not found: %s\n", command1);
}
