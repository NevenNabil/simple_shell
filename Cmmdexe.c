#include "AN_shell.h"
/**
 * cmmdexe - function execute a command specified
 * @argv: string argu//ment
 * Return:Nothing
 */
void cmmdexe(char **argv)
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
