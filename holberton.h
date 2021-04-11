#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <errno.h>

extern char **environ;

int _putchar(char ch);
int _puts(char *str);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *get_input(void);
char **str_to_arg(char *line);
int spw_process(char *args[]);
char *_getenv(const char *name);


#endif
