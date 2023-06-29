#include "shell.h"

/**
 * string_comapre - compares between 2 strings
 * @str1: string pinter one
 * @str2: string pointer two
 * Return: diference
 */
int string_compare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
	}
	return (0);
}

/**
 * copy_str - copies a string
 * @destination: the destination pointer
 * @source: the source pointer
 * Return: pointer to destination
 */
char *copy_str(char *destination, char *source)
{
	char *s = destination;

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (s);
}

/**
 * separate_str - function separate string
 * @s: string
 * @sp: separator
 * Return: split path
 */

char **separate_str(char *s, char *sp)
{
	char *an, **sep_str;
	int k = 0;

	an = strtok(s, sp);
	sep_str = (char **)_calloc(100, sizeof(char *));

	if (!sep_str)
	{
		free(sep_str);
		return (NULL);
	}

	while (an)
	{
		sep_str[k] = an;
		an = strtok(NULL, sp);
		k++;
	}
	return (sep_str);
}

/**
 * concat_str - concatenates 2 strings
 * @destination: string 1
 * @sourc: string
 * Return: pointer to destination
 */

char *concat_str(char *destination, char *sourc)
{
	int l, k;

	for (k = 0; destination[k] != '\0'; k += 1)
	{}

	for (l = 0; sourc[l] != '\0'; l += 1)
	{
		destination[k] = sourc[l];
		k++;
	}
	destination[k] = '\0';
	return (destination);
}

/**
 * string_length - function takes a string str as an argument
 * @str: string
 * Return: the length
 */

int string_length(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}
