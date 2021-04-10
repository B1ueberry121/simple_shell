#include "holberton.h"

/**
 * _puts -  prints a string of characters to stdout
 * Return: 
 */

int _puts(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * _putchar - prints a single character to stdout
 * Return: 
 */

int _putchar(char ch)
{
	return (write(STDOUT_FILENO, &ch, 1));
}

/**
 * _strlen - gets the length of a string
 * Return: size of bytes it needs
 */

int _strlen(char *str)
{

	int bytes;

	for (bytes = 0; str[bytes] != '\0'; bytes++);

	return (bytes);
}

/**
 * _strcmp - compares characters in two strings
 * @str1: first string
 * @str2: second string
 * Return: Negative number if str2 is greater than str1
 * Positive number if str2 is lesser than str1
 * 0 if str1 and str2 are the same
 */

int _strcmp(char *str1, char *str2)
{
	int ind;

	for (ind = 0; str1[ind] == str2[ind]; ind++)
	{
		if (str1[ind] == '\0')
			return (0);
	}
	
	return (str1[ind] - str2[ind]);
}
