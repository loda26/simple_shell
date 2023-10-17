#include "shell.h"

/**
 * _putchar - print the input string
 * @c: input string
 * Return: string
 */

void _putchar(const char *c)
{
	write(STDOUT_FILENO, c, _strlen(c));
}
