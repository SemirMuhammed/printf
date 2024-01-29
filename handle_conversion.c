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
		{'d', print_decimal},
		{'i', print_integer},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexa_lower},
		{'X', print_hexa_upper},
		{'S', print_non_string},
		{'p', print_pointer},
		{'\0', NULL}
	};

	while (conv_list[++j].sp != '\0')
		if (conv_list[j].sp == format[*i])
			return (conv_list[j].func(buf, ap));

	if (format[*i] == '\0')
		return (fs_c);
	fs_c = write(1, "%%", 1);
	fs_c += write(1, &format[*i], 1);
	return (fs_c);
}

