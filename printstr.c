#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * print_str - Prints a string to stdout
 * @args: va_list input
 * @len: int input
 *
 * Return: The number of characters printed
 */
int print_str(va_list args, int len)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
		len += write(1, str, strlen(str));
		return (len);
	}
	len += write(1, str, strlen(str));
	return (len);
}
