#ifndef AN_SHELL_H
#define AN_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
extern char *builtin_str[];

void cmmdexe(char **argv);
char *get_location(char *command);
int string_length(const char *str);
char *concat_str(char *destination, char *source);
char *duplicate_str(const char *string);
char *copy_str(char *destination, char *source);
char *find_location(char *cmd);
size_t string_compare(const char *str1, const char *str2, size_t n);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
#endif
