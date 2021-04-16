#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;
int __attribute((unused)) EXIT_CODE;

void _free(char *line, char **args, char *path, char **drc);
int _checkbuilts(char *line);
char **_path(char *path);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _putchar(char ch);
int _puts(char *str);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *get_input(void);
char **str_to_arg(char *line);
int spw_process(char *args[]);
char *_getenv(const char *nvs);
void _sighandler(int sig_num);

#endif
