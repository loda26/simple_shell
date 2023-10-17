#include "shell.h"

/**
 * read_command - read input command
 *
 * Return: command
*/

char *read_command(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t x;

	if (isatty(STDIN_FILENO))
		_putchar("#cisfun$ ");
	x = getline(&line, &line_size, stdin);
	if (x == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
