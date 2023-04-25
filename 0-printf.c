#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - Prints a single character to stdout
 * @c: The character to print
 *
 * Return: The number of characters printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Prints a string to stdout
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_str(char *str)
{
	return (write(1, str, strlen(str)));
}
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
				char c = (char) va_arg(args, int);

				len += print_char(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				len += print_str(str);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				len = print_int(num, len);
			}
			else if (*format == '%')
			{
				len += print_char('%');
			}
		}
		else
		{
			len += print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (len);
}
