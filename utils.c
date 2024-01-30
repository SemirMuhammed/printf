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

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsigned(unsigned long int num, mod_t mod)
{
	if (mod.length == L_LONG)
		return (num);
	else if (mod.length == L_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
