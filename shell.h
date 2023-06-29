#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void *_calloc(unsigned int nmemb, unsigned int size);
void _env(void);
char **_split(char *str, char *sep);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *search_path(char *command);
int _strlength(char *s);
char *_getenv(char *env_var);
int execute(char **args);
int empty_line(char *buff);

#endif /* SHELL_H */
