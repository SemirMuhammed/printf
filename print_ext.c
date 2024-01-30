#include "main.h"

/**
 * ext_decimal - extension of print_decimal
 * @mod: Structure
 * @padd: padding modifier
 * @flag_ch: flag character
 * @bc: buffer count
 * @buf: buffer
 * @len: length
 *
 * Return: number of char printed
 */
int ext_decimal(mod_t mod, char padd, char flag_ch
		, int bc, char buf[], int len)
{
	int i, padd_start = 1;

	if (mod.width > len)
	{
		for (i = 1; i < mod.width - len + 1; i++)
			buf[i] = padd;
		buf[i] = '\0';
		if (mod.flag & F_MINUS && padd == ' ')
		{
			if (flag_ch)
				buf[--bc] = flag_ch;
			return (write(1, &buf[bc], len)
				+ write(1, &buf[1], i - 1));
		}
		else if (!(mod.flag & F_MINUS) && padd == ' ')
		{
			if (flag_ch)
				buf[--bc] = flag_ch;
			return (write(1, &buf[1], i - 1)
				+ write(1, &buf[bc], len));
		}
		else if (!(mod.flag & F_MINUS) && padd == '0')
		{
			if (flag_ch)
				buf[--padd_start] = flag_ch;
			return (write(1, &buf[padd_start], i - padd_start) +
				write(1, &buf[bc], len - (1 - padd_start)));
		}
	}
	if (flag_ch)
		buf[--bc] = flag_ch;
	return (write(1, &buf[bc], len));
}

/**
 * ext_unsign - extension of print_unsign
 * @mod: Structure
 * @padd: padding modifier
 * @bc: buffer count
 * @buf: buffer
 * @len: length
 *
 * Return: number of char printed
 */
int ext_unsign(mod_t mod, char padd, int bc, char buf[], int len)
{
	int i;

	if (mod.precision == 0 && bc == BUF_SIZE - 1 && buf[bc] == '0')
		return (0);

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

		if (mod.flag & F_MINUS)
			return (write(1, &buf[bc], len) + write(1, &buf[0], i));
		else
			return (write(1, &buf[0], i) + write(1, &buf[bc], len));
	}

	return (write(1, &buf[bc], len));
}

/**
 * ext_pointer - extension of print_pointer
 * @mod: Structure
 * @padd: padding modifier
 * @flag_ch: flag character
 * @bc: buffer count
 * @buf: buffer
 * @len: length
 *
 * Return: number of char printed
 */
int ext_pointer(mod_t mod, int len, int padd, int bc, char flag_ch, char buf[])
{
	int i, padd_start = 1;

	if (mod.width > len)
	{
		for (i = 3; i < mod.width - len + 3; i++)
			buf[i] = padd;
		buf[i] = '\0';
		if (mod.flag & F_MINUS && padd == ' ')
		{
			buf[--bc] = 'x';
			buf[--bc] = '0';
			if (flag_ch)
				buf[--bc] = flag_ch;
			return (write(1, &buf[bc], len)
				+ write(1, &buf[3], i - 3));
		}
		else if (!(mod.flag & F_MINUS) && padd == ' ')
		{
			buf[--bc] = 'x';
			buf[--bc] = '0';
			if (flag_ch)
				buf[--bc] = flag_ch;
			return (write(1, &buf[3], i - 3)
				+ write(1, &buf[bc], len));
		}
		else if (!(mod.flag & F_MINUS) && padd == '0')
		{
			if (flag_ch)
				buf[--padd_start] = flag_ch;
			buf[1] = '0', buf[2] = 'x';
			return (write(1, &buf[padd_start], i - padd_start) +
				write(1, &buf[bc], len - (1 - padd_start) - 2));
		}
	}
	buf[bc--] = 'x';
	buf[bc] = '0';
	if (flag_ch)
		buf[--bc] = flag_ch;
	len = BUF_SIZE - bc;
	return (write(1, &buf[bc], len));
}
