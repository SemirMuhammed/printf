#include "main.h"

/**
 * handle_conversion - handles format specifiers based on their type
 * @format: format
 * @i: iteration of format
 * @buf: buffer
 * @ap: list of argument parameters
 *
 * Return: 1 or 2
 */
int handle_conversion(const char *format, int *i, char buf[], va_list ap)
{
	int j = -1, fs_c = -1;
	conv_t conv_list[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	while (conv_list[++j].sp != '\0')
		if (conv_list[j].sp == format[*i])
			fs_c = conv_list[j].func(buf, ap);

	if (fs_c > 0)
		(*i)++;

	return (fs_c);
}
