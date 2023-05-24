#include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
	unsigned int s;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{NULL, NULL}
	};

	for (s = 0; check[s].f != NULL; s++)
	{
		if (_strcmpr(vars->av[0], check[s].name) == 0)
			break;
	}
	if (check[s].f != NULL)
		check[s].f(vars);
	return (check[s].f);
}

/**
 * new_exit - exit program
 * @vars: variables
 * Return: void
 */
void new_exit(vars_t *vars)
{
	int condition;

	if (_strcmpr(vars->av[0], "exit") == 0 && vars->av[1] != NULL)
	{
		condition = _atoi(vars->av[1]);
		if (condition == -1)
		{
			vars->status = 2;
			print_error(vars, ": Outlawed number: ");
			_puts2(vars->av[1]);
			_puts2("\n");
			free(vars->commands);
			vars->commands = NULL;
			return;
		}
		vars->status = condition;
	}
	free(vars->buffer);
	free(vars->av);
	free(vars->commands);
	free_env(vars->env);
	exit(vars->status);
}

/**
 * _env - prints the current environment
 * @vars: struct of variables
 * Return: void.
 */
void _env(vars_t *vars)
{
	unsigned int t;

	for (t = 0; vars->env[t]; t++)
	{
		_puts(vars->env[t]);
		_puts("\n");
	}
	vars->status = 0;
}

/**
 * new_setenv - create a new environment variable, or edit an existing variable
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void new_setenv(vars_t *vars)
{
	char **k;
	char *var2;

	if (vars->av[1] == NULL || vars->av[2] == NULL)
	{
		print_error(vars, ": Incorrect no. of arguments\n");
		vars->status = 2;
		return;
	}
	k = find_key(vars->env, vars->av[1]);
	if (k == NULL)
		add_key(vars);
	else
	{
		var2 = add_value(vars->av[1], vars->av[2]);
		if (var2 == NULL)
		{
			print_error(vars, NULL);
			free(vars->buffer);
			free(vars->commands);
			free(vars->av);
			free_env(vars->env);
			exit(34);
		}
		free(*k);
		*k = var2;
	}
	vars->status = 0;
}

/**
 * new_unsetenv - remove an environment variable
 * @vars: pointer to a struct of variables
 *
 * Return: void
 */
void new_unsetenv(vars_t *vars)
{
	char **k, **m_env;

	unsigned int i, j;

	if (vars->av[1] == NULL)
	{
		print_error(vars, ": Incorrect no. of arguments\n");
		vars->status = 2;
		return;
	}
	k = find_key(vars->env, vars->av[1]);
	if (k == NULL)
	{
		print_error(vars, ": No variable to unset");
		return;
	}
	for (i = 0; vars->env[i] != NULL; i++)
		;
	m_env = malloc(sizeof(char *) * i);
	if (m_env == NULL)
	{
		print_error(vars, NULL);
		vars->status = 34;
		new_exit(vars);
	}
	for (i = 0; vars->env[i] != *k; i++)
		m_env[i] = vars->env[i];
	for (j = i + 1; vars->env[j] != NULL; j++, i++)
		m_env[i] = vars->env[j];
	m_env[i] = NULL;
	free(*k);
	free(vars->env);
	vars->env = m_env;
	vars->status = 0;
}
