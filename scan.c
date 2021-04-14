#include "holberton.h"

/**
 * get_input - reads user input and stores it into a buffer
 * Return: The line read from stdin as a string
 */

char *get_input(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int bytesread = 0;

	bytesread = getline(&buffer, &bufsize, stdin);

	if (bytesread == EOF)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			_putchar('\n');
		}
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	else if (bytesread == -1)
	{
		perror("Error: could not read");
		exit(EXIT_FAILURE);
	}

	buffer[bytesread - 1] = '\0';
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
	int ind;
	char delim[] = "\n ";

	args = malloc(sizeof(char *) * 100);
	if (args == NULL)
	{
		exit(EXIT_FAILURE);
	}
	args[0] = strtok(line, delim);

	for (ind = 0; args[ind] != NULL; ind++)
	{
		args[ind + 1] = strtok(NULL, delim);
	}

	args[ind + 1] = NULL;

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
		EXIT_CODE = WEXITSTATUS(wstatus);
	}

	return (status);
}

/**
 * _checkbuilts - checks if the user input equals one of the shell kwords
 * @line: users input
 */

void _checkbuilts(char *line)
{
	int ind;

	if (_strcmp(line, "exit") == 0)
	{
		free(line);
		exit(EXIT_CODE);
	}

	else if (_strcmp(line, "env") == 0)
	{
		for (ind = 0; environ[ind]; ind++)
		{
			_puts(environ[ind]);
			_putchar('\n');
		}
		return;
	}
	else
	{
		return;
	}
}
