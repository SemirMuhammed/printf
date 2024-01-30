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
	int bc = 0, i;
	char c = va_arg(ap, int), padd = ' ';

	if (mod.flag & F_ZERO)
		padd = '0';
	buf[bc++] = c;
	buf[bc] = '\0';

	if (mod.width > 1)
	{
		buf[BUF_SIZE - 1] = '\0';
		for (i = 0; i < mod.width - 1; i++)
			buf[BUF_SIZE - i - 2] = padd;

		if (mod.flag & F_MINUS)
			return (write(1, &buf[0], 1) +
					write(1, &buf[BUF_SIZE - i - 1], mod.width - 1));
		else
			return (write(1, &buf[BUF_SIZE - i - 1], mod.width - 1) +
					write(1, &buf[0], 1));
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
	int bc = BUF_SIZE - 1, len;
	long int num = va_arg(ap, int);
	char padd = ' ', flag_ch = 0;

	num = convert_size_number(num, mod);

	if (num == 0)
		buf[bc--] = '0';
	if ((mod.flag & F_ZERO) && !(mod.flag & F_MINUS))
		padd = '0';
	if (num < 0)
		num *= -1, flag_ch = '-';
	else if (mod.flag & F_PLUS)
		flag_ch = '+';
	else if (mod.flag & F_SPACE)
		flag_ch = ' ';
	len = bc;
	buf[BUF_SIZE] = '\0';
	while (num > 0)
	{
		buf[bc--] = '0' + (num % 10);
		num /= 10;
	}
	len = BUF_SIZE - ++bc;
	if (mod.precision == 0 && bc == BUF_SIZE - 2
		&& buf[bc] == '0' && mod.width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (mod.precision == 0 && bc == BUF_SIZE - 2 && buf[bc] == '0')
		buf[bc] = padd = ' '; /* mod.width is displayed with padding ' ' */
	if (mod.precision > 0 && mod.precision < len)
		padd = ' ';
	while (mod.precision > len)
		buf[--bc] = '0', len++;
	if (flag_ch != 0)
		len++;

	return (ext_decimal(mod, padd, flag_ch, bc, buf, len));
}

