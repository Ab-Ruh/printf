#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - Prints a formatted string to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				print_char(args, len);
			}
			else if (*format == 's')
			{
				print_str(args, len);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				print_int(num, len);
			}
			else if (*format == '%')
			{
				len += write(1, "%", 1);
			}
		}
		else
		{
			len += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (len);
}
