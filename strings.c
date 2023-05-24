#include "shell.h"

/**
 * _puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _puts(char *str)
{
	ssize_t n, len2;

	n = _strlen(str);
	len2 = write(STDOUT_FILENO, str, n);
	if (len2 != n)
	{
		perror("Error");
		return (-1);
	}
	return (len2);
}

/**
 * _strdup - returns pointer to new mem alloc space which contains copy
 * @strtodup: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *strtodup)
{
	char *cp;
	int len3, p;

	if (strtodup == 0)
		return (NULL);

	for (len3 = 0; strtodup[len3]; len3++)

	cp = malloc((len3 + 1) * sizeof(char));

	for (p = 0; p <= len3; p++)
		cp[p] = strtodup[p];

	return (cp);
}

/**
 * _strcmpr - compares two strings
 * @strcmp1: first string, of two, to be compared in length
 * @strcmp2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	int g;

	g = 0;
	while (strcmp1[g] == strcmp2[g])
	{
		if (strcmp1[g] == '\0')
			return (0);
		g++;
	}
	return (strcmp1[g] - strcmp2[g]);
}

/**
 * _strcat - concatenates two strings
 * @strc1: first string
 * @strc2: second string
 * Return: pointer
 */
char *_strcat(char *strc1, char *strc2)
{
	char *newst;
	unsigned int len1, len2, n_len, i, j;

	len1 = 0;
	len2 = 0;
	if (strc1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}
	n_len = len1 + len2 + 2;
	newst = malloc(n_len * sizeof(char));
	if (newst == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		newst[i] = strc1[i];
	newst[i] = '/';
	for (j = 0; j < len2; j++)
		newst[i + 1 + j] = strc2[j];
	newst[len1 + len2 + 1] = '\0';
	return (newst);
}

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int len4;

	len4 = 0;

	for (len4 = 0; str[len4]; len4++)
		;
	return (len4);
}
