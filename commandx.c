#include "AN_shell.h"

/**
 * commandx - function excute acommand specified
 * @argv: string argument
 * Return:Nothing
 */
void commandx(char **argv)
{
	char *cmd = NULL, *real_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		real_cmd = find_location(cmd);

		if (execve(real_cmd, argv, NULL) == -1)
		{
			perror("Error: No such as dirctory or file");
		}
	}
}
