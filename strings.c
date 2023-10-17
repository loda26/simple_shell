#include "shell.h"

/**
 * _strdup - double the length
 * @str: input string
 * Return: string
*/

char *_strdup(const char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
		return (NULL);
	for (len = 0; *str != '\0'; len++)
		str++;
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcmp - compare between two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer
*/

int _strcmp(char *s1, char *s2)
{
	int ptr;

	ptr = (int)*s1 - (int)*s2;
	for (; *s1;)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		ptr = (int)*s1 - (int)*s2;
	}
	return (ptr);
}

/**
 * _strlen - return the length of string
 * @s: input string
 * Return: pointer length
*/

int _strlen(const char *s)
{
	int i;

	if (!s)
		return (0);
	for (i = 0; *s != '\0'; s++)
		i++;
	return (i);
}

/**
 * _strcat - adds to strings
 * @dest: first string
 * @src: second string
 * Return: pointer to string
*/

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}

/**
 * _strcpy - copy the string
 * @dest: string
 * @src: string
 * Return: string
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
