#include "main.h"

/**
 * get_flag - identify the flag attribute
 * @format: format
 * @i: iteration of format
 *
 * Return: flag indicator
 */
int get_flag(const char *format, int *i)
{
	int fc = 0, flags = F_NULL;
	flag_t flg[] = {
		{'+', F_PLUS},
		{' ', F_SPACE},
		{'#', F_HASHTAG},
		{'0', F_ZERO},
		{'-', F_MINUS},
		{'\0', F_NULL}
	};

	while (format[(*i)] != '\0')
	{
		while (flg[fc].f_char)
		{
			if (flg[fc].f_char == format[*i])
			{
				(*i)++;
				flags |= (flg[fc].f_int);
				break;
			}
			fc++;
		}
		if (flg[fc].f_char == '\0')
			break;
		fc = 0;
	}
	return (flags);
}

/**
 * get_length - identify the length attribute
 * @format: format
 * @i: iteration of format
 *
 * Return: length indicator
 */
int get_length(const char *format, int *i)
{
	int length = L_NULL;

	if (format[*i] == 'l')
		length |= L_LONG;
	if (format[*i] == 'h')
		length |= L_SHORT;
	if (length)
		(*i)++;
	return (length);
}

/**
 * get_width - identify the width attribute
 * @format: format
 * @i: iteration of format
 *
 * Return: field width
 */
int get_width(const char *format, int *i, va_list ap)
{
	int width = 0;

	while (format[*i] != '\0')
	{
		if (format[*i] >= '0' && format[*i] <= '9')
		{
			width *= 10;
			width += format[(*i)++] - '0';
		}
		else if (format[*i] == '*')
		{
			(*i)++;
			width = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	return (width);
}

/**
 * get_precision - identify the precision attribute
 * @format: format
 * @i: iteration of format
 *
 * Return: precision number
 */
int get_precision(const char *format, int *i, va_list ap)
{
	int precision = 0;

	if (format[*i] != '.')
		return (precision);
	(*i)++;
	while (format[*i] != '\0')
	{
		if (format[*i] >= '0' && format[*i] <= '9')
		{
			precision *= 10;
			precision += format[(*i)++] - '0';
		}
		else if (format[*i] == '*')
		{
			(*i)++;
			precision = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	return (precision);
}
