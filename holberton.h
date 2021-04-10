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

#define INPUT_SIZE 510
#define CUTTING_WORD " \n"
#define ENDING_WORD "exit"
#define RESET 0

void DisplayPrompt(void);
char **execFunction(char *input, char **argv, int *saf, int *cmdlen);
void trashcoll(char **argv, int size);

static int *numofcmd;
static int *cmdlen;

#endif
