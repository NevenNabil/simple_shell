#ifndef AN_SHELL_H
#define AN_SHELL_H
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;

void cmmdexe(char **argv);
char *get_location(char *command);
int string_length(const char *str);
char *concat_str(char *destination, char *source);
char *duplicate_str(const char *string);
char *copy_str(char *destination, char *source);
char *find_location(char *cmd);

#endif
