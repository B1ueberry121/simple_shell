#include "holberton.h"

/**
 * main - is the entry point
 *
 * Return: returns an integer
 */
int main(void)
{
	while (1)
	{
		promptfunc();
	/*will display prompt*/
		commandprocess();
	/*will read the input from terminal*/
		if (fork() != 0)
			wait(NULL);
		else
		{
			execute_command();
	/*will execute the command*/
		}
	}
}
