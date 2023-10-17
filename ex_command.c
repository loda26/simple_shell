#include "shell.h"

/**
 * reverse_str - reverse a string
 * @str: input string
 * @len: length
 * Return: reversed string
 */

void reverse_str(char *str, int len)
{
	char tmp;
	int start;
	int end = len - 1;

	for (start = 0; start < end; start++, end--)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
	}
}

/**
 * _itoa - convert intgr to string
 * @n: input int
 * Return: string
*/

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_str(buffer, i);
	return (_strdup(buffer));
}

/**
 * printerror - print an error massage
 * @name: input name
 * @cmd: input command
 * @idx: input index
 * Return: error msg
*/

void printerror(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(index);
}

/**
 * ex_command - function to excute the command
 * @command: input command
 * @argv: input argv
 * @idx: input index
 * Return: Command
*/

int ex_command(char **command, char **argv, int idx)
{
	char *cmd;
	pid_t child_pid;
	int status;

	cmd = _getpath(command[0]);
	if (!cmd)
	{
		printerror(argv[0], command[0], idx);
		freearray(command);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(cmd, command, environ) == -1)
		{
			free(cmd);
			freearray(command);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		freearray(command);
		free(cmd);
	}
	return (WEXITSTATUS(status));
}
