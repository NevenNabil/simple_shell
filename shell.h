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
char **separate_str(char *s, char *sp);
char *concat_str(char *destination, char *sourc);
int string_compare(char *str1, char *str2);
char *copy_str(char *destination, char *source);
char *search_path(char *command);
int string_length(char *str);
char *_getenv(char *env_var);
int execute(char **args);
int empty_line(char *buff);

#endif /* SHELL_H */
