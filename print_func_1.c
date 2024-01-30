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
	int i = 0, len, bc = BUF_SIZE - 1;
	unsigned long int num = va_arg(ap, unsigned int);
	char padd = ' ';

	num = convert_size_unsign(num, mod);
	if (num == 0)
		return (write(1, "0", 1));
	buf[BUF_SIZE] = '\0';
	while (num)
	{
		buf[bc--] = '0' + (num % 10);
		num /= 10;
	}

	len = BUF_SIZE - ++bc;
	if (mod.precision == 0 && bc == BUF_SIZE - 1 && buf[bc] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (mod.precision > 0 && mod.precision < len)
		padd = ' ';

	while (mod.precision > len)
	{
		buf[--bc] = '0';
		len++;
	}

	if ((mod.flag & F_ZERO) && !(mod.flag & F_MINUS))
		padd = '0';

	if (mod.width > len)
	{
		for (i = 0; i < mod.width - len; i++)
			buf[i] = padd;

		buf[i] = '\0';

		if (mod.flag & F_MINUS) /* Asign extra char to left of buf [buf>padd]*/
		{
			return (write(1, &buf[bc], len) + write(1, &buf[0], i));
		}
		else /* Asign extra char to left of padding [padd>buf]*/
		{
			return (write(1, &buf[0], i) + write(1, &buf[bc], len));
		}
	}

	return (write(1, &buf[bc], len));
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
	int i = 0, len, bc = BUF_SIZE - 1;
	unsigned long int num = va_arg(ap, unsigned int), HASH_num = num;
	char padd = ' ';

	num = convert_size_unsign(num, mod);
	if (num == 0)
		return (write(1, "0", 1));
	buf[BUF_SIZE] = '\0';
	while (num)
	{
		buf[bc--] = '0' + (num % 8);
		num /= 8;
	}
	if (mod.flag & F_HASHTAG && HASH_num != 0)
		buf[bc--] = '0';

	len = BUF_SIZE - ++bc;
	if (mod.precision == 0 && bc == BUF_SIZE - 1 && buf[bc] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (mod.precision > 0 && mod.precision < len)
		padd = ' ';

	while (mod.precision > len)
	{
		buf[--bc] = '0';
		len++;
	}

	if ((mod.flag & F_ZERO) && !(mod.flag & F_MINUS))
		padd = '0';

	if (mod.width > len)
	{
		for (i = 0; i < mod.width - len; i++)
			buf[i] = padd;

		buf[i] = '\0';

		if (mod.flag & F_MINUS) /* Asign extra char to left of buf [buf>padd]*/
		{
			return (write(1, &buf[bc], len) + write(1, &buf[0], i));
		}
		else /* Asign extra char to left of padding [padd>buf]*/
		{
			return (write(1, &buf[0], i) + write(1, &buf[bc], len));
		}
	}

	return (write(1, &buf[bc], len));
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
	int bc = BUF_SIZE - 1, len, i;
	unsigned long int num = va_arg(ap, unsigned int), HASH_num = num;
	char padd = ' ';

	num = convert_size_unsign(num, mod);
	if (num == 0)
		return (write(1, "0", 1));
	buf[BUF_SIZE] = '\0';
	while (num)
	{
		if ((num % 16) > 9)
			buf[bc--] = '0' + (num % 16) + 39;
		else
			buf[bc--] = '0' + (num % 16);
		num /= 16;
	}
	if (mod.flag & F_HASHTAG && HASH_num != 0)
	{
		buf[bc--] = 'x';
		buf[bc--] = '0';
	}

	len = BUF_SIZE - ++bc;
	if (mod.precision == 0 && bc == BUF_SIZE - 1 && buf[bc] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (mod.precision > 0 && mod.precision < len)
		padd = ' ';

	while (mod.precision > len)
	{
		buf[--bc] = '0';
		len++;
	}

	if ((mod.flag & F_ZERO) && !(mod.flag & F_MINUS))
		padd = '0';

	if (mod.width > len)
	{
		for (i = 0; i < mod.width - len; i++)
			buf[i] = padd;

		buf[i] = '\0';

		if (mod.flag & F_MINUS) /* Asign extra char to left of buf [buf>padd]*/
		{
			return (write(1, &buf[bc], len) + write(1, &buf[0], i));
		}
		else /* Asign extra char to left of padding [padd>buf]*/
		{
			return (write(1, &buf[0], i) + write(1, &buf[bc], len));
		}
	}

	return (write(1, &buf[bc], len));
}

