#include "main.h"

/**
 * print_hexa_upper - calls write to print hexadecimal in uppercase
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_hexa_upper(char buf[], va_list ap)
{
	int i = BUF_SIZE - 1, len;
	unsigned long int num = va_arg(ap, unsigned int);

	if (num == 0)
		buf[i--] = '0';
	buf[BUF_SIZE] = '\0';
	while (num)
	{
		if ((num % 16) > 9)
			buf[i--] = '0' + (num % 16) + 7;
		else
			buf[i--] = '0' + (num % 16);
		num /= 16;
	}

	i++;
	len = BUF_SIZE - i;

	return (write(1, &buf[i], len));
}

/**
 * print_non_string - calls write to print sting
 * and prints non-printable characters as hex
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_non_string(char buf[], va_list ap)
{
	int i = 0, bc = 0;
	char *str = va_arg(ap, char *), ch = '0';

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (str[i] < 0)
			str[i] *= -1;
		if (str[i] >= 32 && str[i] < 127)
			buf[bc++] = str[i++];
		else
		{
			buf[bc++] = '\\';
			buf[bc++] = 'x';
			ch = '0';
			if ((str[i] / 16) > 9)
				ch = 'A' - 10;
			buf[bc++] = ch + (str[i] / 16);
			ch = '0';
			if ((str[i] % 16) > 9)
				ch = 'A' - 10;
			buf[bc++] = ch + (str[i++] % 16);
		}
	}
	buf[bc] = '\0';

	return (write(1, &buf[0], bc));
}

/**
 * print_pointer - calls write to print address of argument
 * @buf: buffer
 * @ap: argument parameter
 *
 * Return: number of characters printed
 */
int print_pointer(char buf[], va_list ap)
{
	int bc = BUF_SIZE - 1, len;
	void *ptr = va_arg(ap, void *);
	unsigned long address;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));

	buf[BUF_SIZE] = '\0';
	address = (unsigned long)(ptr);
	if (address == 0)
		buf[bc--] = '0';
	while (address > 0)
	{
		if ((address % 16) > 9)
			buf[bc--] = '0' + (address % 16) + 39;
		else
			buf[bc--] = '0' + (address % 16);
		address /= 16;
	}

	buf[bc--] = 'x';
	buf[bc] = '0';
	len = BUF_SIZE - bc;

	return (write(1, &buf[bc], len));

}

/**
 * print_reverse - Prints reverse string.
 * @ap: List of arguments
 * @buf: Buffer array to handle print
 *
 * Return: Numbers of chars printed
 */

int print_reverse(char buf[], va_list ap)
{
	char *str = va_arg(ap, char *);
	int i, bc = 0;

	if (str == NULL)
		str = ")Null(";
	i = _strlen(str) - 1;
	while (i >= 0)
		buf[bc++] = str[i--];
	return (write(1, &buf[0], bc));
}
/**
 * print_rot13string - Print a string in rot13.
 * @ap: List of arguments
 * @buf: Buffer array to handle print
 *
 * Return: Numbers of chars printed
 */
int print_rot13string(char buf[], va_list ap)
{
	char *str;
	unsigned int i, j;
	int bc = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(ap, char *);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				buf[bc++] = out[j];
				break;
			}
		}
		if (!in[j])
		{
			buf[bc++] = str[i];
		}
	}
	buf[bc] = '\0';
	return (write(1, &buf[0], bc));
}
