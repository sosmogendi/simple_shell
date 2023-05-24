#include "shell.h"

/**
 * add_key - create a new environment variable
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void add_key(vars_t *vars)
{
	unsigned int t;
	char **m_env;

	for (t = 0; vars->env[t] != NULL; t++)
		;
	m_env = malloc(sizeof(char *) * (t + 2));
	if (m_env == NULL)
	{
		print_error(vars, NULL);
		vars->status = 127;
		new_exit(vars);
	}
	for (t = 0; vars->env[t] != NULL; t++)
		m_env[t] = vars->env[t];
	m_env[t] = add_value(vars->av[1], vars->av[2]);
	if (m_env[t] == NULL)
	{
		print_error(vars, NULL);
		free(vars->buffer);
		free(vars->commands);
		free(vars->av);
		free_env(vars->env);
		free(m_env);
		exit(74);
	}
	m_env[t + 1] = NULL;
	free(vars->env);
	vars->env = m_env;
}

/**
 * find_key - finds an environment variable
 * @env: array of environment variables
 * @key: environment variable to find
 *
 * Return: pointer to address of the environment variable
 */
char **find_key(char **env, char *key)
{
	unsigned int a, b, len2;

	len2 = _strlen(key);
	for (a = 0; env[a] != NULL; a++)
	{
		for (b = 0; b < len2; b++)
			if (key[b] != env[a][b])
				break;
		if (b == len2 && env[a][b] == '=')
			return (&env[a]);
	}
	return (NULL);
}

/**
 * add_value - create a new environment variable string
 * @key: variable name
 * @value: variable value
 *
 * Return: pointer to the new string;
 */
char *add_value(char *key, char *value)
{
	unsigned int len1, len2, x, y;
	char *new1;

	len1 = _strlen(key);
	len2 = _strlen(value);
	new1 = malloc(sizeof(char) * (len1 + len2 + 2));
	if (new1 == NULL)
		return (NULL);
	for (x = 0; key[x] != '\0'; x++)
		new1[x] = key[x];
	new1[x] = '=';
	for (y = 0; value[y] != '\0'; y++)
		new1[x + 1 + y] = value[y];
	new1[x + 1 + y] = '\0';
	return (new1);
}

/**
 * _atoi - converts a string into an integer
 * @str: string to convert
 *
 * Return: the integer value, or -1 if an error occurs
 */
int _atoi(char *str)
{
	unsigned int u, digits1;
	int num = 0, num_t;

	num_t = INT_MAX;
	for (digits1 = 0; num_t != 0; digits1++)
		num_t /= 10;
	for (u = 0; str[u] != '\0' && u < digits1; u++)
	{
		num *= 10;
		if (str[u] < '0' || str[u] > '9')
			return (-1);
		if ((u == digits1 - 1) && (str[u] - '0' > INT_MAX % 10))
			return (-1);
		num += str[u] - '0';
		if ((u == digits1 - 2) && (str[u + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (u > digits1)
		return (-1);
	return (num);
}
