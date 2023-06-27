#include "AN_shell.h"

/**
 * concat_str - concat_strenates two strings
 * @destination: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *concat_str(char *destination, char *source)
{
	char *output = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (output);
}
