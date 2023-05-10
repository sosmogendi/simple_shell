#include "shell.h"

/**
 * main - entry point to the shell
 * @argc: number of args
 * @argv: array of args
 *
 * Return: 0
 */

int main(void)
{
	char *args[BUFFER_SIZE / 2 + 1];
	char buf[BUFFER_SIZE];
	pid_t pid;
	int status2;

	while (1)
	{
		printf(PROMPT);
		fflush(stdout);
	
		if (fgets(buf, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}
	
		if (buf[strlen(buf) - 1] == '\n')
		{
			buf[strlen(buf) - 1] = '\0';
		}
		args[0] = buf;
		args[1] = NULL;
		pid = fork();
	
		if (pid < 0)
		{
			fprintf(stderr, "fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				fprintf(stderr, "Command was not found\n");
				exit(1);
			}
		}
	       else
	       {
		       waitpid(pid, &status2, 0);
	       }
	}
	return (0);
}
