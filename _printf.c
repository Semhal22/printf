#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - Prints format
 * @format: format to be printed
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	print types[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{NULL, NULL}
	};
	va_list args;
	int num;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	num = _print(format, args, types);

	va_end(args);
	return (num);
}
/**
 * _print - Prints format for loop
 * @format: format to be printed
 * @args: arguments
 * @types: types
 *
 * Return: nubmer of characters printed
 */
int _print(const char *format, va_list args, print types[])
{
	int i, j, num = 0;

	for (i = 0; format[i] != '\0' && format; i++)
	{
		if (format[i] != '%')
			num += _putchar(format[i]);
		else
		{
			i++;
			if (validate_format(format[i]))
			{
				for (j = 0; types[j].type != NULL; j++)
				{
					if (format[i] == *(types[j].type))
					{
						num += (types[j].func)(args);
						break;
					}
				}
			}
			else
			{
				if (format[i] == '\0')
					return (-1);
				else if (format[i] == '%')
					num += _putchar(format[i]);
				if (format[i] != '%')
				{
					num += _putchar('%');
					num += _putchar(format[i]);
				}
			}
		}
	}
	return (num);
}
/**
 * validate_format - Checks if a format is a proper format specifier
 * @format: format to be checked
 *
 * Return: 1 if format exists,
 * 0 if not
 */
int validate_format(char format)
{
	char formats[] = {'c', 's', 'i', 'd', 'b', 'u', 'o', 'x', 'X'};
	int i = 0;

	while (formats[i] != '\0')
	{
		if (format == formats[i])
			return (1);
		i++;
	}
	return (0);
}
