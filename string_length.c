#include "AN_shell.h"
/**
 * string_length - function takes a string str as an argument
 * @str: string argument
 * Return: the length
 */
int string_length(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
