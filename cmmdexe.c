#include "AN_shell.h"
/**
* lsh_launch - function launch environmental variable
* @args: name of variable
*Return:-1
*/
int lsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("hsh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perror("hsh");
	} else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
char *builtin_str[] = {
	"cd",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_exit
};

/**
 * cmmdexe - function excute acommand specified
 * @argv: string argument
 * Return:Nothing
 */
int cmmdexe(char **argv)
{
	char *cmd = NULL, *real_cmd = NULL;
	int i;

	if (argv[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < (sizeof(builtin_str) / sizeof(char *)); i++)
	{
		if ((argv) && (string_compare(argv[0], builtin_str[i], 1) == 0))
		{
			cmd = argv[0];
			real_cmd = find_location(cmd);
			if (execve(real_cmd, argv, NULL) == -1)
			{
				perror("Error: No such as dirctory or file");
			}
		}
		if (string_compare(argv[0], builtin_str[i], 1) == 0)
		{
			return ((*builtin_func[i])(argv));
		}
	}
	return (lsh_launch(argv));
}
/**
* lsh_cd - function change directory
* @args: name of variable
*Return:1
*/
int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	} else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}
/**
* lsh_exit - exit function
* @args: name of variable
*Return:-1
*/
int lsh_exit(char **args)
{
	printf("exitting AN_shell...\n");
	exit(-1);
	return (-1);
}

