#include "shell.h"

/**
 * main - Entry point
 * Return: int
 */

int main(void)
{
	char *bf = NULL, **ac;
	size_t sized_read = 0;
	ssize_t sized_bf = 0;
	int st_ex = 0;

	while (1)
	{
		if (isatty(0))
			printf("AN_shell $ ");

		sized_bf = getline(&bf, &sized_read, stdin);
		if (sized_bf == -1 || string_compare("exit\n", bf) == 0)
		{
			free(bf);
			break;
		}
		bf[sized_bf - 1] = '\0';

		if (string_compare("env", bf) == 0)
		{
			_environment();
			continue;
		}

		if (line_hollow(bf) == 1)
		{
			st_ex = 0;
			continue;
		}

		ac = separate_str(bf, " ");
		ac[0] = search_path(ac[0]);

		if (ac[0] != NULL)
			st_ex = execute(ac);
		else
			perror("Error");
		free(ac);
	}
	return (st_ex);
}
