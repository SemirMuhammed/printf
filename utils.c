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
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @mod: Structure of Modifiers
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, mod_t mod)
{
	if (mod.length == L_LONG)
		return (num);
	else if (mod.length == L_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @mod: Structure of Modifiers
 *
 * Return: Casted value of num
 */
long int convert_size_unsign(unsigned long int num, mod_t mod)
{
	if (mod.length == L_LONG)
		return (num);
	else if (mod.length == L_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
