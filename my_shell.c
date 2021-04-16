#include "holberton.h"

/**
 * main - is the entry point
 * Return: 0
 */

int main(void)
{
	char *line, **args, *path, **drc, *entpath;
	int flag = 0, interactor = isatty(STDIN_FILENO), ind = 0, pathfind = 0;
	struct stat st;

	do {
		if (interactor == 1)
			_puts("$ ");
		line = get_input();
		if (line == NULL)
			continue;
		if (_checkbuilts(line))
			continue;
		args = str_to_arg(line);
		path = _getenv("PATH");
		drc = _path(path);
		while (drc[ind])
		{
			entpath = _strcat(drc[ind], args[0]);
			if (stat(entpath, &st) == 0)
			{
				args[0] = entpath;
				pathfind = 1;
				break;
			}
			else
			{
				free(entpath);
				ind++;
			}
		}
		flag = spw_process(args);
		if (flag == 1)
		{
			perror(args[0]);
			_free(line, args, path, drc);
			exit(127);
		}
		if (pathfind == 1)
			free(entpath);
		_free(line, args, path, drc);
	} while (1);
	return (0);
}
