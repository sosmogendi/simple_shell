#include "shell.h"

/**
 * make_env - make the shell environment from the environment passed to main
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */
char **make_env(char **env)
{
	char **m_env = NULL;
	size_t k;

	for (k = 0; env[k] != NULL; k++)
		;
	m_env = malloc(sizeof(char *) * (k + 1));
	if (m_env == NULL)
	{
		perror("Error");
		exit(1);
	}
	for (k = 0; env[k] != NULL; k++)
		m_env[k] = _strdup(env[k]);
	m_env[k] = NULL;
	return (m_env);
}

/**
 * free_env - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void free_env(char **env)
{
	unsigned int a;

	for (a = 0; env[a] != NULL; a++)
		free(env[a]);
	free(env);
}
