#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE 1024

#define F_NULL 0
#define F_PLUS 1
#define F_SPACE 2
#define F_HASHTAG 4
#define F_ZERO 8
#define F_MINUS 16

#define L_NULL 0
#define L_LONG 1
#define L_SHORT 2

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

/**
 * struct flag - Stucture of flag attribute
 * @f_char: flag indicator
 * @f_int: flag value
 */
typedef struct flag
{
	char f_char;
	int f_int;
} flag_t;

/**
 * struct mod - Stucture of format modifier
 * @flag: flag mod
 * @width: flag width
 * @precision: flag precision
 * @length: flag length
 */
typedef struct mod
{
	int flag;
	int width;
	int precision;
	int length;
} mod_t;


int _printf(const char *format, ...);
void print_buffer(char *buf, int *bc);
int handle_conversion(const char *format, int *i, char *buffer, va_list ap);
int get_flag(const char *format, int *i);
int get_width(const char *format, int *i);
int get_precision(const char *format, int *i);
int get_length(const char *format, int *i);

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
int print_non_string(char buf[], va_list ap);
int print_pointer(char buf[], va_list ap);
int print_reverse(char buf[], va_list ap);
int print_rot13string(char buf[], va_list ap);

int _strlen(char *str);
char *int_to_string(int num);

#endif /* MAIN_H */
