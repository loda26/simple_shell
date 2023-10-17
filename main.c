#include "shell.h"

/**
 * main - main function
 * @argc: argument c
 * @argv: argument v
  * Return: void
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	char **command;
	int status = 0, index = 0;
	(void) argc;

	while (1)
	{
		line = read_command();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO)) /*to not print $*/
				_putchar("\n");
			return (status);
		}
		index++;
		command = tokenizer(line);
		if (!command)
			continue;
		if (_strcmp(command[0], "exit") == 0)
		{
			freearray(command);
			return (status);
		}
		else if (_strcmp(command[0], "env") == 0)
		{
			print_env();
			freearray(command);
		}
		else
			status = ex_command(command, argv, index);
	}
}
