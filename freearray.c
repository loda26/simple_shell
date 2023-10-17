#include "shell.h"

/**
 * freearray - function thats frees an array
 * @array: input array
 * Retuen: empty array
 */

void freearray(char **array)
{
	int i;

if (!array)
	return;
for (i = 0; array[i]; i++)
	{
	free(array[i]);
	array[i] = NULL;
	}
free(array);
}
