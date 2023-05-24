#include "shell.h"

/**
 * _realloc - reallocates a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to number of elements in the old array
 *
 * Return: pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new_m;
	size_t f;

	new_m = malloc(sizeof(char *) * ((*size) + 10));
	if (new_m == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (f = 0; f < (*size); f++)
	{
		new_m[f] = ptr[f];
	}
	*size += 10;
	free(ptr);
	return (new_m);
}
