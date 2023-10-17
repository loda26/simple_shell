#include "shell.h"

/**
 * _getenv - get the env
 * @ptr: input
 * Return: NULL
 */

char *_getenv(char *ptr)
{

char *buf, *key, *value, *env;
int i;

	for (i = 0; environ[i]; i++)
	{
	buf = _strdup(environ[i]);
	key = strtok(buf, "=");
	if (_strcmp(key, ptr) == 0)
	{
	value = strtok(NULL, "\n");
	env = _strdup(value);
	free(buf);
	return (env);
	}
	free(buf);
	}
	return (NULL);
}
