#include "shell.h"

/**
 * get_env - function gets environment variables
 * @variable_env: environment variables
 * Return:  environment variables result
 */

char *get_env(char *variable_env)
{
	int j = 0, n;
	int stus;

	while (environ[j])
	{
		stus = 1;

		for (n = 0; environ[j][n] != '='; n++)
		{
			if (environ[j][n] != variable_env[n])
				stus = 0;
		}
		if (stus == 1)
			break;
		j++;
	}
	return (&environ[j][n + 1]);
}

/**
 * _environment - function prints env
*/
void _environment(void)
{
	int a = 0;

	while (environ[a])
	{
		printf("%s\n", environ[a]);
		a++;
	}
}
