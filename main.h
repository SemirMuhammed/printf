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

int _strlen(char *str);

#endif /* MAIN_H */
