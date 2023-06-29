#include "shell.h"

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: array
 * @size: size
 * Return: pointer or NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int index = 0;
	char *ptr = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	for (; index < (nmemb * size); index++)
		ptr[index] = 0;

	return (ptr);
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

