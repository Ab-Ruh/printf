#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - Prints a single character to stdout
 * @args: va_list input
 * @len: int input
 *
 * Return: The number of characters printed
 */
int print_char(va_list args, int len)
{
	char c = (char) va_arg(args, int);

	len += (write(1, &c, 1));
	return (len);
}
