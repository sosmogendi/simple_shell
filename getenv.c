#include "shell.h"

/**
 * get_environ - returns the string array of the environ
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - gets rid of an environment variable
 * @info: Structure containing potential arguments.
 *  Return: 1 on success, 0 otherwise
 * @var: the string env var property
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t f = 0;
	char *s;

	if (!node || !var)
		return (0);

	while (node)
	{
		s = starts_with(node->str, var);
		if (s && *s == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), f);
			f = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		f++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Indicates a new environment variable
 *@info: Structure containing potential arguments.        
 *@var: the string env var property
 *@value: the string env var value
 *Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *s;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		s = starts_with(node->str, var);
		if (s && *s == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

