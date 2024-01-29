#include "main.h"

/**
 * print_hexa_upper - calls write to print hexadecimal in uppercase
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_hexa_upper(char buf[], va_list ap)
{
	int i = BUF_SIZE - 1, len;
	unsigned long int num = va_arg(ap, unsigned int);

	if (num == 0)
		buf[i--] = '0';
	buf[BUF_SIZE] = '\0';
	while (num)
	{
		if ((num % 16) > 9)
			buf[i--] = '0' + (num % 16) + 7;
		else
			buf[i--] = '0' + (num % 16);
		num /= 16;
	}

	i++;
	len = BUF_SIZE - i;

	return (write(1, &buf[i], len));
}

