#include "holberton.h"

/**
 * main - is the entry point
 * Return: 0
 */

int main(void)
{
	char *line, **args;
	int flag, interactor = isatty(STDIN_FILENO), ind;

	do {
		if (interactor == 1)
			_puts("($) ");

		line = get_input();

		if (_strcmp(line, "exit") == 0)
		{
			interactor = 0;
		}
		else if (_strcmp(line, "env") == 0)
		{

		for (ind = 0; environ[ind]; ind++)
		{
			_puts(environ[ind]);
				_putchar('\n');
			}
		}
		else
		{
			args = str_to_arg(line);
			flag = spw_process(args);
			if (flag == 1)
			{
				perror("execution fail");
				free(line);
				free(args);
				exit(EXIT_FAILURE);
			}
			free(args);
		}
		free(line);
	} while (interactor);
		return (0);
}
