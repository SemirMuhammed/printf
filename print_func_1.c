#include "main.h"

/**
 * print_integer - calls write to print integer
 * @buf: buffer
 * @ap: argument parameter
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_integer(char buf[], va_list ap, mod_t mod)
{
	return (print_decimal(buf, ap, mod));
}

/**
 * print_binary - calls write to print binary
 * @buf: buffer
 * @ap: argument parameter
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_binary(char buf[], va_list ap, mod_t mod)
{
	int i = BUF_SIZE - 1, len;
	unsigned int num = va_arg(ap, unsigned int);

	(void)(mod);
	if (num == 0)
		buf[i--] = '0';
	buf[BUF_SIZE] = '\0';
	while (num)
	{
		buf[i--] = '0' + (num % 2);
		num /= 2;
	}

	i++;
	len = BUF_SIZE - i;

	return (write(1, &buf[i], len));
}

/**
 * print_unsigned - calls write to print unsigned
 * @buf: buffer
 * @ap: argument parameter
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_unsigned(char buf[], va_list ap, mod_t mod)
{
	int i = 0, len;
	unsigned long int num = va_arg(ap, unsigned int), decimal;

	num = convert_size_unsigned(num, mod);
	if (num == 0)
		return (write(1, "0", 1));
	decimal = num;
	while (decimal != 0)
	{
		decimal /= 10;
		i++;
	}

	len = i;
	buf[i--] = '\0';
	while (num)
	{
		buf[i--] = '0' + (num % 10);
		num /= 10;
	}

	return (write(1, &buf[0], len));
}

/**
 * print_octal - calls write to print octal
 * @buf: buffer
 * @ap: argument parameter
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_octal(char buf[], va_list ap, mod_t mod)
{
	int i = BUF_SIZE - 1, len;
	unsigned long int num = va_arg(ap, unsigned int), HASH_num = num;

	num = convert_size_unsigned(num, mod);
	if (num == 0)
		buf[i--] = '0';
	buf[BUF_SIZE] = '\0';
	while (num)
	{
		buf[i--] = '0' + (num % 8);
		num /= 8;
	}
	if (mod.flag & F_HASHTAG && HASH_num != 0)
		buf[i--] = '0';

	i++;
	len = BUF_SIZE - i;

	return (write(1, &buf[i], len));
}

/**
 * print_hexa_lower - calls write to print hexadecimal in lowercase
 * @buf: buffer
 * @ap: argument parameter
 * @mod: structure of modifiers
 *
 * Return: number of characters printed
 */
int print_hexa_lower(char buf[], va_list ap, mod_t mod)
{
	int i = BUF_SIZE - 1, len;
	unsigned long int num = va_arg(ap, unsigned int);

	num = convert_size_unsigned(num, mod);
	if (num == 0)
		buf[i--] = '0';
	buf[BUF_SIZE] = '\0';
	while (num)
	{
		if ((num % 16) > 9)
			buf[i--] = '0' + (num % 16) + 39;
		else
			buf[i--] = '0' + (num % 16);
		num /= 16;
	}

	i++;
	len = BUF_SIZE - i;

	return (write(1, &buf[i], len));
}

