#include "main.h"

/**
 * print_integer - calls write to print integer
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_integer(char buf[], va_list ap)
{
	return (print_decimal(buf, ap));
}
