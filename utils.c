#include "main.h"

/**
 * _strlen - get string length
 * @str: string
 *
 * Return: string length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
