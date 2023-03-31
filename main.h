#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct printf - Prints an argument based on it's type
 * @type: type of the argument
 * @func: Function to be called
 *
 */

typedef struct printf
{
	char *type;
	int (*func)(va_list args);
} print;

int _putchar(char c);
int _printf(const char *format, ...);
int _print(const char *format, va_list args, print types[]);
int validate_format(char format);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_number(int n);
int print_binary(va_list args);
int print_unsigned_int(va_list args);
int print_octal(va_list args);
int recursion_func(unsigned int dividend, int divisor, char type);
int print_hexa_upper(va_list args);
int print_hexa_lower(va_list args);

#endif /* MAIN_H */
