#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _strlen - Calculates length of a string
 * @str: String
 *
 * Return: length
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
/**
 * print_char - Prints a character
 * @args: argument to be printed
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char character;

	character = va_arg(args, int);
	return (write(1, &character, 1));
}
/**
 * print_string - Prints a string
 * @args: argument to be printed
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
		return (write(1, str, _strlen(str)));
	}
	return (write(1, str, _strlen(str)));
}
