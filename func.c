#include "shell.h"

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @numemb: array
 * @bufsize: size
 * Return: pointer or NULL
 */

void *_calloc(unsigned int numemb, unsigned int bufsize)
{
	unsigned int index = 0;
	char *pointer = NULL;

	if (numemb == 0 || bufsize == 0)
		return (NULL);

	pointer = malloc(numemb * bufsize);

	if (pointer == NULL)
		return (NULL);

	for (; index < (numemb * bufsize); index++)
		pointer[index] = 0;

	return (pointer);
}

/**
 * execute - execute command path, child process
 * @args: arguments
 * Return: exit status
 */

int execute(char **args)
{
	int id = fork(), status;

	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	return (status);
}

/**
 * search_path - search file between the path
 * @command: cmd
 * Return: cmd path
 */

char *search_path(char *command)
{
	char *path = get_env("PATH"), *copyPath;
	char **splitPath;
	char *concatPath = NULL;
	int i = 0, path_length = 0;
	struct stat info;

	if (stat(command, &info) == 0)
		return (command);

	copyPath = malloc(string_length(path) + 1);

	copyPath = copy_str(copyPath, path);
	splitPath = separate_str(copyPath, ":");

	while (splitPath[i])
	{
		path_length = string_length(splitPath[i]);

		if (splitPath[i][path_length - 1] != '/')
			concatPath = concat_str(splitPath[i], "/");

		concatPath = concat_str(splitPath[i], command);

		if (stat(concatPath, &info) == 0)
			break;

		i++;
	}

	free(copyPath);

	if (!splitPath[i])
	{
		free(splitPath);
		return (NULL);
	}

	free(splitPath);
	return (concatPath);
}

