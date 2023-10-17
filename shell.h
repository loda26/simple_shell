#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void freearray(char **array);

/*string functions*/
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void _putchar(const char *c);

/*main functions*/
char *read_command(void);
char **tokenizer(char *line);
char *_getenv(char *ptr);
char *_getpath(char *command);
void reverse_str(char *str, int len);
char *_itoa(int n);
void printerror(char *name, char *cmd, int idx);
int ex_command(char **command, char **argv, int idx);
void print_env(void);

#endif
