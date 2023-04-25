#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

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
len += write(1, &c, 1);
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
len += write(1, str, strlen(str));
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
