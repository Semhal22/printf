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

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);

#endif /* MAIN_H */
