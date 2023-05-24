#include "shell.h"
/**
 * check_match - checks if a character matches any in a string
 * @c: character to check
 * @str: string to check
 *
 * Return: 1 if match, 0 if not
 */
unsigned int check_if_match(char c, const char *str)
{
	unsigned int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (c == str[x])
			return (1);
	}
	return (0);
}

/**
 * new_strtok - custom strtok
 * @str: string to tokenize
 * @delim: delimiter to tokenize against
 *
 * Return: pointer to the next token or NULL
 */
char *new_strtok(char *str, const char *delim)
{
	static char *token_1;
	static char *cur_token;
	unsigned int x;

	if (str != NULL)
		cur_token = str;
	token_1 = cur_token;
	if (token_1 == NULL)
		return (NULL);
	for (x = 0; cur_token[x] != '\0'; x++)
	{
		if (check_if_match(cur_token[x], delim) == 0)
			break;
	}
	if (cur_token[x] == '\0' || cur_token[x] == '#')
	{
		cur_token = NULL;
		return (NULL);
	}
	token_1 = cur_token + x;
	cur_token = token_1;
	for (x = 0; cur_token[x] != '\0'; x++)
	{
		if (check_if_match(cur_token[x], delim) == 1)
			break;
	}
	if (cur_token[x] == '\0')
		cur_token = NULL;
	else
	{
		cur_token[x] = '\0';
		cur_token = cur_token + x + 1;
		if (*cur_token == '\0')
			cur_token = NULL;
	}
	return (token_1);
}
