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
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_char(char buf[], va_list ap, mod_t mod)
{
	int bc = 0;
	char c = va_arg(ap, int), padd = ' ';

	if (mod.flag & F_ZERO)
		padd = '0';
	buf[bc++] = c;
	while (--mod.width > 1)
	{
		buf[bc++] = padd;
	}
	buf[bc] = '\0';

	if (!(mod.flag & F_MINUS))
	{
		buf[0] = padd;
		buf[bc - 1] = c;
	}

	return (write(1, &buf[0], bc));
}

/**
 * print_string - calls write to print string parameter
 * @buf: buffer
 * @ap: argument parameter
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_string(char buf[], va_list ap, mod_t mod)
{
	char *str = va_arg(ap, char *);

	(void)(buf);
	(void)(mod);
	if (str == NULL)
		str = "(null)";
	return (write(1, &str[0], _strlen(str)));
}

/**
 * print_percent - calls write to print pecent
 * @buf: buffer
 * @ap: argument parameter
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_percent(char buf[], va_list ap, mod_t mod)
{
	(void)(buf);
	(void)(ap);
	(void)(mod);
	return (write(1, "%%", 1));
}

/**
 * print_decimal - calls write to print decimal
 * @buf: buffer
 * @ap: argument parameter
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_decimal(char buf[], va_list ap, mod_t mod)
{
	int i = 0, len;
	long int num = va_arg(ap, int), decimal;

	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
		num *= -1, buf[i++] = '-';
	else if (mod.flag & F_PLUS)
		buf[i++] = '+';
	else if (mod.flag & F_SPACE)
		buf[i++] = ' ';
	decimal = num;
	while (decimal != 0)
		decimal /= 10, i++;

	len = i;
	buf[i--] = '\0';
	while (num != 0)
	{
		buf[i--] = '0' + (num % 10);
		num /= 10;
	}

	return (write(1, &buf[0], len));
}

