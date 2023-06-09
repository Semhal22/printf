#include "main.h"
#include <stdarg.h>
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
	return (_putchar(character));
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
/**
 * print_int - Prints an integer
 * @args: argument to be printed
 *
 * Return: number
 */
int print_int(va_list args)
{
	int count = 0, m = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;
	if (m < 0)
	{
		_putchar('-');
		m = m * -1;
		n = m;
		count++;
	}
	if (n == 0)
		return (_putchar('0'));
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	print_number(m);
	return (count);
}

/**
 * print_number - prints an integer
 * @n: integer to be printed
 *
 * Return: void
 */
int print_number(int n)
{
	unsigned int num;

	num = n;
	if (num / 10)
		print_number(num / 10);
	return (_putchar(num % 10 + '0'));
}
