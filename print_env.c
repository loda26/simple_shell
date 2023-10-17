#include "shell.h"

/**
 * print_env - function to not print $
 *
 * Return: output
*/

void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_putchar(environ[i]);
		_putchar("\n");
	}
}
