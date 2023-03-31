#include <stdarg.h>
#include "main.h"
/**
 * print_unsigned_int - Prints an unsigned integer
 * @args: arguments of the list
 *
 * Return: Number of characters printed
 */
int print_unsigned_int(va_list args)
{
	unsigned int num, temp;
	int count = 0;

	num = va_arg(args, unsigned int);
	temp = num;
	if (temp == 0)
		return (_putchar('0'));
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	print_number(num);
	return (count);
}
/**
 * print_octal - Prints an octal number
 * @args: Arguments of the list
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
	int count = 0;
	unsigned int num, temp;

	num = va_arg(args, unsigned int);
	temp = num;
	if (temp == 0)
		return (_putchar('0'));
	while (temp > 0)
	{
		temp /= 8;
		count++;
	}
	recursion_func(num, 8, 'o');
	return (count);
}
/**
 * recursion_func - Calls itself in order to print characters
 * @dividend: The number to be divided
 * @divisor: A number that divises the dividend
 * @type: Type of the number we want to print
 * o for octal. l for lower hexadecimal and u for upper hexadecimal
 *
 * Return: Number of characters printed
 */
int recursion_func(unsigned int dividend, int divisor, char type)
{
	char add = '0';
	unsigned int quotient = dividend / divisor;
	unsigned int remainder = dividend % divisor;

	if (quotient)
		recursion_func(quotient, divisor, type);
	if (type == 'o')
		return (_putchar(remainder + '0'));
	else if (type == 'u')
		add = (remainder < 10) ? 48 : 55;
	else
		add = (remainder < 10) ? 48 : 85;
	return (_putchar(remainder + add));
}
/**
 * print_hexa_upper - Prints a hexadecimal number in uppercase
 * @args: Arguments of the list
 *
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list args)
{
	int count = 0;
	unsigned int num, temp;

	num = va_arg(args, unsigned int);
	temp = num;
	if (temp == 0)
		return (_putchar('0'));
	while (temp > 0)
	{
		temp /= 16;
		count++;
	}
	recursion_func(num, 16, 'u');
	return (count);
}
/**
 * print_hexa_lower - Prints a hexadecimal number in lowercase
 * @args: Arguments of the list
 *
 * Return: Number of characters printed
 */
int print_hexa_lower(va_list args)
{
	int count = 0;
	unsigned int num, temp;

	num = va_arg(args, unsigned int);
	temp = num;
	if (temp == 0)
		return (_putchar('0'));
	while (temp > 0)
	{
		temp /= 16;
		count++;
	}
	recursion_func(num, 16, 'l');
	return (count);
}
