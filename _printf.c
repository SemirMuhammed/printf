#include "main.h"

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

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
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
			++i;
			fs_c = handle_conversion(format, &i, buf, ap);
			if (fs_c == -1)
				return (-1);
			c += fs_c;
		}
		++i;
	}

	print_buffer(buf, &bc);

	va_end(ap);

	return (c);
}
