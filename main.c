#include "shell.h"

/**
 * main - start point
 * @ac: counts arguments
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int gh = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (gh)
		: "r" (gh));

	if (ac == 2)
	{
		gh = open(av[1], O_RDONLY);
		if (gh == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readgh = gh;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
