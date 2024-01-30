#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output to stdout (standard output stream)
 * according to the format
 * @format: format
 *
 * Return: the number of characters printed (excluding the null
 * byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int i = 0, c = 0, bc = 0, fs_c = 0;
	char buf[BUF_SIZE];
	va_list ap;
	mod_t mod;

	(void)mod;
	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buf[bc++] = format[i];
			if (bc == BUF_SIZE)
				print_buffer(buf, &bc);
			c++;
		}
		else
		{
			print_buffer(buf, &bc);
			i++;
			mod.flag = get_flag(format, &i);
			mod.width = get_width(format, &i);
			mod.precision = get_precision(format, &i);
			mod.length = get_length(format, &i);
			fs_c = handle_conversion(format, &i, buf, ap);
			if (fs_c == -1)
				return (-1);
			c += fs_c;
		}
	}

	print_buffer(buf, &bc);

	va_end(ap);

	return (c);
}
