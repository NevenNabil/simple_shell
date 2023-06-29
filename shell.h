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
void _environment(void);
char **separate_str(char *s, char *sp);
char *concat_str(char *destination, char *sourc);
int string_compare(char *str1, char *str2);
char *copy_str(char *destination, char *source);
char *search_path(char *command);
int string_length(char *str);
char *get_env(char *variable_env);
int execute(char **args);
int line_hollow(char *buffer);

#endif /* SHELL_H */
