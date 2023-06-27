#include "AN_shell.h"
/**
 * main - Entry point
 * @an: number of command line argument
 * @argv:pointer to an array of command line argument
 * Return:0 success, non-zero-fail
 */
int main(int an, char **argv)
{
	char *create_prompt = "AN_shell $ ";
	char *strline = NULL, *strline_copy = NULL, *takens;
	size_t a = 0;
	ssize_t read_char;
	const char *delima = "\n";
	int number_tokeens = 0, i;
	(void)
	while (1)
	{
		printf("%s", create_prompt);
		read_char = getline(&strline, &a, stdin);
		if (read_char == -1)
		{
			printf("Out AN_shell\n");
			return (-1);
		}
		strline_copy = malloc(sizeof(char) * read_char);
		if (strline_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		copy_str(strline_copy, strline);
		takens = strtok(strline, delima);
		for (; takens != NULL; number_tokeens++)
			takens = strtok(NULL, delima);
		number_tokeens++;
		argv = malloc(sizeof(char *) * number_tokeens);
		takens = strtok(strline_copy, delima);
		for (i = 0; takens != NULL; i++)
			argv[i] = malloc(sizeof(char) * string_length(takens));
			copy_str(argv[i], takens);
			takens = strtok(NULL, delima);
		argv[i] = NULL;
		cmmdexe(argv);
	}
	free(strline_copy);
	free(strline);
	return (0);
}
