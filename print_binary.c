#include "main.h"
/**
 * print_binary - Prints an unsigned number
 * @args: arguments passed to the function
 *
 * Return: Numbers of char printed.
 */
int print_binary(va_list args)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			_putchar(z);
			count++;
		}
	}
	return (count);
}
