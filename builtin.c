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
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
/**
* lsh_execute - function execute environmental variable
* @args: name of variable
*Return:lsh_launch(args)
*/
int lsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{return ((*builtin_func[i])(args));
		}
	}
	return (lsh_launch(args));
	char *cmd = NULL, *real_cmd = NULL;

	if (args)
	{
		cmd = args[0];
		real_cmd = find_location(cmd);

		if (execve(real_cmd, args, NULL) == -1)
		{
			perror("Error: No such as dirctory or file");
		}
	}
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
* lsh_help - help function
* @args: name of variable
*Return:1
*/
int lsh_help(char **args)
{
	int i;

	printf("AN's HSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
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
	exit(0);
	return (-1);
}

