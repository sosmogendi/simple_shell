#include "shell.h"

/**
 * my_getline - Reads a line of input from the standard input and returns it as a dynamically allocated string
 *
 * Return: The read line as a dynamically allocated string, or NULL on failure or end of input.
 */

char *my_getline(void)
{
	static char buf[BUFFER_SIZE];
	static size_t position ;
	static ssize_t chars_read;
	char *line1 = NULL;
	size_t line1_size = 0;
	ssize_t newline_index;
	size_t i;
	size_t length1;
	ssize_t remaining_chars;

	while (1)
	{
	newline_index = -1;
	for (i = position; i < (size_t)chars_read; i++)
	{
	if (buf[i] == '\n')
	{
	newline_index = (ssize_t)i;
	break;
	}
	}
	if (newline_index != -1)
	{
	length1 = (size_t)(newline_index - position + 1);
	line1 = realloc(line1, line1_size + length1);
	if (line1 == NULL)
	{
	perror("realloc");
	exit(EXIT_FAILURE);
	}
	memcpy(line1 + line1_size, buf + position, length1);
	line1_size += length1;
	position = (size_t)(newline_index + 1);
	break;
	}
	else
	{
	remaining_chars = chars_read - position;
	line1 = realloc(line1, line1_size + (size_t)remaining_chars);
	if (line1 == NULL)
	{
	perror("realloc");
	exit(EXIT_FAILURE);
	}
	memcpy(line1 + line1_size, buf + position, (size_t)remaining_chars);
	line1_size += (size_t)remaining_chars;
	position = 0;
	chars_read = read(STDIN_FILENO, buf, BUFFER_SIZE);
	if (chars_read == -1)
	{
	perror("read");
	exit(EXIT_FAILURE);
	}
	if (chars_read == 0)
	{
	if (line1_size > 0)
	{
	line1 = realloc(line1, line1_size + 1);
	if (line1 == NULL)
	{
	perror("realloc");
	exit(EXIT_FAILURE);
	}
	line1[line1_size] = '\0';
	}
	break;
	}
	}
	}
	return (line1);
}
