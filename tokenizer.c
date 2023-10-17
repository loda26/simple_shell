#include "shell.h"

/**
 * tokenizer - tokenize the input command
 * @line: input command line
 * Return: array
 */

char **tokenizer(char *line)
{
	char *buf = NULL;
	char *token = NULL;
	char **array = NULL;
	int i;

	if (!line)
	return (NULL);

	buf = _strdup(line);
	token = strtok(buf, " \t\n");
	if (token == NULL)
	{
	free(line);
	free(buf);
	return (NULL);
	}
	for (i = 0; token; i++)
	token = strtok(NULL, " \t\n");
	free(buf);
	array = malloc(sizeof(char *) * (i + 1));
	if (!array)
	{
	free(line);
	return (NULL);
	}
	token = strtok(line, " \t\n");
	for (i = 0; token; i++)
	{
	array[i] = _strdup(token);
	token = strtok(NULL, " \t\n");
	}
	free(line);
	array[i] = NULL;
	return (array);
}
