#include "shell.h"

/**
 * print_error - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @message: message to print
 *
 * Return: void
 */
void print_error(vars_t *vars, char *message)
{
	char *sum;

	_puts2(vars->argv[0]);
	_puts2(": ");
	sum = _uitoa(vars->sum);
	_puts2(sum);
	free(sum);
	_puts2(": ");
	_puts2(vars->av[0]);
	if (message)
	{
		_puts2(message);
	}
	else
		perror("");
}

/**
 * _puts2 - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _puts2(char *str)
{
	ssize_t n, len1;

	n = _strlen(str);
	len1 = write(STDERR_FILENO, str, n);
	if (len1 != n)
	{
		perror("Error");
		exit(1);
	}

}

/**
 * _uitoa - converts an unsigned int to a string
 * @sum: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa(unsigned int sum)
{
	char *num2;
	unsigned int tmp, digits2;

	tmp = sum;
	for (digits2 = 0; tmp != 0; digits2++)
		tmp /= 10;
	num2 = malloc(sizeof(char) * (digits2 + 1));
	if (num2 == NULL)
	{
		perror("Error1");
		exit(16);
	}
	num2[digits2] = '\0';
	for (--digits2; sum; --digits2)
	{
		num2[digits2] = (sum % 10) + '0';
		sum /= 10;
	}
	return (num2);
}
