#include "AN_shell.h"
/**
 *string_compare - compares between  two strings.
 *@str1: string 1
 *@str2: string 2
 *@n: number of chas
 * Return: diference
 */
size_t string_compare(const char *str1, const char *str2, size_t n)
{
	size_t k, l;

	for (l = 0; str1[l] != '\0' && l < n; l++)
	{
		k = str1[l] - str2[l];

		if (k != 0)
		{
			return (k);
		}
	}
	return (0);
}
