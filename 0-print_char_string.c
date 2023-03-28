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
		{NULL, NULL}
	};
	va_list args;
	int num;

	va_start(args, format);
	if (format == NULL)
		return (-1);
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

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			num++;
		}
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
			else if (format[i] != '\0')
			{
				write(1, &format[i - 1], 1);
				num++;
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
	char formats[] = {'c', 's'};
	int i = 0;

	while (formats[i] != '\0')
	{
		if (format == formats[i])
			return (1);
		i++;
	}
	return (0);
}
