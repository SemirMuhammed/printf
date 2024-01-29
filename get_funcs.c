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
	int fc = 0;
	flag_t flg[] = {
		{'+', F_PLUS},
		{' ', F_SPACE},
		{'#', F_HASHTAG},
		{'\0', '\0'}
	};

	while (flg[fc].f_char)
	{
		if (flg[fc++].f_char == format[*i])
		{
			write(1, &format[*i], 1);
			(*i)++;
			return (flg[fc - 1].f_int);
		}
	}
	return (-1);
}
