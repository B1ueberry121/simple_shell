#include "holberton.h"

/**
 * get_input - reads user input and stores it into a buffer
 * Return: The line read from stdin as a string
 */

char *get_input(void)
{
	char *buffer = NULL;
	size_t bufsize = 1024;
	int bytesRead = 0;

	buffer = malloc(sizeof(char) * bufsize);

	bytesRead = read(STDIN_FILENO, buffer, bufsize);

	if (bytesRead == 0)
	{
		_putchar('\n');
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	else if (bytesRead == -1)
	{
		perror("Error: could not read");
		exit(EXIT_FAILURE);
	}

	buffer[bytesRead - 1] = '\0';
	fflush(stdin);

	return (buffer);
}

/**
 * str_to_arg - splits string from buffer into single worded arguments
 * @line: a command with optional arguments
 * Return: An array of word separated tokens from line
 */

char **str_to_arg(char *line)
{
	char **args;
	int index;
	char delim[] = "\n ";

	args = malloc(100 * sizeof(char *));
	if (args == NULL)
		exit(EXIT_FAILURE);

	args[0] = strtok(line, delim);

	for (index = 0; args[index] != NULL; index++)
	{
		args[index + 1] = strtok(NULL, delim);
	}

	args[index + 1] = NULL;

	return (args);
}

/**
 * spw_process - creates a child process and executes it to a command
 * @args: an array of single worded arguments
 * Return: 0 if process executed succesfully, otherwise 1.
 */

int spw_process(char *args[])
{
	pid_t forkedPid;
	int status = 0, wstatus;

	forkedPid = fork();
	if (forkedPid == -1)
	{
		perror("Error: forking");
	}

	if (forkedPid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			status = 1;
			return (status);
		}
	}
	else
	{
		wait(&wstatus);
	}

	return (status);
}
