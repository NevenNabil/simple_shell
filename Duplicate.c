#include "AN_shell.h"

/**
 * duplicate_str - duplicates a string
 * @string: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *duplicate_str(const char *string)
{
	int length = 0;
	char *output;

	if (string == NULL)
		return (NULL);
	while (*string++)
		length++;
	output = malloc(sizeof(char) * (length + 1));
	if (!output)
		return (NULL);
	for (length++; length--;)
		output[length] = *--string;
	return (output);
}

