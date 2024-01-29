#include "main.h"

/**
 * print_buffer - calls write to print buffer to stdout
 * @buf: string of characters to be printed
 * @bc: number of characters stored in buffer
 *
 * Return: Void
 */
void print_buffer(char *buf, int *bc)
{
	if (*bc > 0)
		write(1, &buf[0], *bc);
	*bc = 0;
}

/**
 * print_char - calls write to print char parameter
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_char(char buf[], va_list ap)
{
	char c = va_arg(ap, int);

	buf[0] = c;
	buf[1] = '\0';

	return (write(1, &buf[0], 1));
}

/**
 * print_string - calls write to print string parameter
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_string(char buf[], va_list ap)
{
	char *str = va_arg(ap, char *);

	(void)(buf);
	if (str == NULL)
		str = "(null)";
	return (write(1, &str[0], _strlen(str)));
}

/**
 * print_percent - calls write to print pecent
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_percent(char buf[], va_list ap)
{
	(void)(buf);
	(void)(ap);
	return (write(1, "%%", 1));
}

/**
 * print_decimal - calls write to print decimal
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_decimal(char buf[], va_list ap)
{
	int i = 0, len;
	long int num = va_arg(ap, int), decimal;

	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		num *= -1;
		buf[0] = '-';
		i++;
	}
	decimal = num;
	while (decimal != 0)
	{
		decimal /= 10;
		i++;
	}

	len = i;
	buf[i--] = '\0';
	while (num != 0)
	{
		buf[i--] = '0' + (num % 10);
		num /= 10;
	}

	return (write(1, &buf[0], len));
}
