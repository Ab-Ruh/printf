#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * print_int - Prints integers
 * @a: int input
 * @len: int input number of characters printed
 * Return: int, The number of characters printed
 */
int print_int(int a, int len)
{
	char c;

	if (a < 0)
	{
		write(1, "-", 1);
		if (a == INT_MIN)
		{
			if (sizeof(int) == 4)
			{
				write(1, "2147483648", 10);
				return (10);
			}
			else if (sizeof(int) == 8)
			{
				write(1, "9223372036854775808", 19);
				return (19);
			}
		}
		else
			a = -1 * a;
	}
	if (a > 9)
	{
		print_int(a / 10, len);
	}
	c = '0' + (a % 10);
	len += write(1, &c, 1);
	return (len);
}
