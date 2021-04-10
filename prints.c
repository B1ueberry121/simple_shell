#include "holberton.h"

/**
 * _putchar - prints a single charater to stdout
 * @ch: char variable
 * @a: int
 * Return: chars
 */

int _putchar(char ch, int a)
{
	return (write(a, &ch, 1));
}

/**
 * _puts - prints a string of character to stdout
 * @str: ptr variable for a string
 * @a: int
 * Return: returns a string
 */

int _puts(char *str, int a)
{
	return (write(a, str, _strlen(str)));
}

/**
 * strlen - gets the length of a string
 * @str: ptr variable
 * Return: size of bytes it needs
 */

int strlen(char *str)
{
	int bytes;

	for (bytes = 0; str[bytes] != '\0'; bytes++)

	return (bytes);
}

/**
 * strcmp - compares charecters in two strings
 * @str1: first str
 * @str2: second str
 * Return: the result of the comparison
 */

int strcmp(char *str1, char *str2)
{
	int ind;

	for (ind = 0; str1[ind] == str2[ind]; ind++)
	{
		if (str1[ind] == '\0')
		{
			return (0);
		}
	}

	return (str1[ind] - str2[ind]);
}
