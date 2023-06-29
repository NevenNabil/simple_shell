#include "shell.h"

/**
 * line_hollow - checks if there is empty line
 * @buffer: line
 * Return: one or zero integer
 */

int line_hollow(char *buffer)
{
	int k;

	for (k = 0; buffer[k] != '\0'; k++)
	{
		if (buffer[k] != ' ')
			return (0);
	}
	return (1);
}
