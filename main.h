#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * struct conv - Stucture of conversion specifiers
 * @sp: specifier indicator
 * @func: the function associated with the specifier
 */
typedef struct conv
{
	char sp;
	int (*func)(char [], va_list);
} conv_t;

int _printf(const char *format, ...);
void print_buffer(char *buf, int *bc);
int handle_conversion(const char *format, int *i, char *buffer, va_list ap);

int print_char(char buf[], va_list ap);
int print_string(char buf[], va_list ap);
int print_percent(char buf[], va_list ap);
int print_decimal(char buf[], va_list ap);
int print_integer(char buf[], va_list ap);
int print_binary(char buf[], va_list ap);
int print_unsigned(char buf[], va_list ap);
int print_octal(char buf[], va_list ap);
int print_hexa_lower(char buf[], va_list ap);
int print_hexa_upper(char buf[], va_list ap);

int _strlen(char *str);
char *int_to_string(int num);

#endif /* MAIN_H */
