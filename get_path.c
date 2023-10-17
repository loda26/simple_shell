#include "shell.h"

/**
 * _getpath - get the path of input command
 * @command: input
 * Return: path or NULL
 */

char *_getpath(char *command)
{
char *path_env, *cmd, *road;
int i;
struct stat st;

for (i = 0; command[i] ; i++)
	{
	if (command[i] == '/')
	{
	if (stat(command, &st) == 0)
	return (strdup(command));
	return (NULL);
	}
	}
path_env = _getenv("PATH");
	if (!path_env)
	return (NULL);
	road = strtok(path_env, ":");
	while (road)
	{
cmd = malloc(_strlen(road) + _strlen(command) + 2);
	if (cmd)
	{
	_strcpy(cmd, road);
	_strcat(cmd, "/");
	_strcat(cmd, command);
	if (stat(cmd, &st) == 0)
	{
	free(path_env);
	return (cmd);
	}
	free(cmd);
	road = strtok(NULL, ":");
	}
	}
	free(path_env);
	return (NULL);
}
