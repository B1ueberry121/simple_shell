#include "holberton.h"

/**
 * _getenv - grabs any env variable
 * @nvs: name of the env varisble to grab
 * Return: value of the string
 */

char *_getenv(const char *nvs)
{
	int ind, n;
	char *match;

	for (ind = 0; environ[ind] != NULL; ind++)
	{
		for (n = 0; environ[ind][n] != '\0'; n++)
		{
			if (environ[ind][n] != nvs[n])
			{
				break;
			}
			else if (environ[ind][n + 1] == '=')
			{
				if (nvs[n + 1] == '\0')
				{
					match = _strdup(&environ[ind][n + 2]);
					return (match);
				}

			}
		}
	}
	return (NULL);
}

/**
 * _path - tokens the path str to directories
 * @path: the entire path string
 * Return: divided path in single directories
 */

char **_path(char *path)
{
	char **drc, del[] = ":";
	int ind, size = 1;

	for (ind = 0; path[ind] != '\0'; ind++)
	{
		if (path[ind] == ':')
		{
			size++;
		}
	}

	drc = malloc(sizeof(char *) * (size + 1));

	if (drc == NULL)
	{
		exit(EXIT_FAILURE);
	}

	drc[0] = strtok(path, del);

	for (ind = 0; drc[ind] != NULL; ind++)
	{
		drc[ind] = strtok(NULL, del);
	}
	return (drc);
}

/**
 * _strcat - concatenates two str
 * @dest: where src will be appended
 * @src: str to be appended
 * Return: dest after src has been appended
 */

char *_strcat(char *dest, char *src)
{
	int ind, x, size = 0;
	char *drc;

	size = _strlen(dest);
	size += _strlen(src);

	drc = malloc(sizeof(char) * (size + 2));

	for (ind = 0; dest[ind] != '\0'; ind++)
	{
		drc[ind] = dest[ind];
	}

	drc[ind] = '/';
	ind++;

	for (x = 0; src[x] != '\0'; x++)
	{
		drc[ind + x] = src[x];
	}

	drc[ind + x] = '\0';

	return (drc);
}

/**
 * _free - frees all alocated memory
 * @line: users input
 * @args: divided input into tokens
 * @path: value of PATH variables in a single str
 * @drc: divided path into directories
 */

void _free(char *line, char **args, char *path, char **drc)
{
	free(drc);
	free(path);
	free(args);
	free(line);
}
