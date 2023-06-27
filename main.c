#include "AN_shell.h"
/**
 * main - Entry point
 * @an: number of command line argument
 * @argv:pointer to an array of command line argument
 * Return:0 success, non-zero-fail
 */
int main(int an, char **argv)
{
	char *strln = NULL, *strln_copy = NULL, *takens, *create_prompt = "AN_shell$";
	size_t a = 0;
	ssize_t read_char;
	const char *delima = "\n";
	int number_tokeens = 0, i;
	(void) an;
	while (1)
	{
		printf("%s", create_prompt);
		read_char = getline(&strln, &a, stdin);
		if (read_char == -1)
		{
			printf("Exitting AN_shell...\n");
			return (-1);
		}
		strln_copy = malloc(sizeof(char) * read_char);
		copy_str(strln_copy, strln);
		takens = strtok(strln, delima);
		for (; takens != NULL; number_tokeens++)
			takens = strtok(NULL, delima);
		number_tokeens++;
		argv = malloc(sizeof(char *) * number_tokeens);
		takens = strtok(strln_copy, delima);
		for (i = 0; takens != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * string_length(takens));
			copy_str(argv[i], takens);
			takens = strtok(NULL, delima);
		}
		argv[i] = NULL;
		cmmdexe(argv);
	}
	free(argv);
	free(strln_copy);
	free(strln);
	return (0);
}
