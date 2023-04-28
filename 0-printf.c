#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
        va_list args;
        int len = 0;

        va_start(args, format);

        while (*format)
        {
                if (*format == '%')
                {
                        format++;
                        switch (*format)
                        {
                                case 'c':
                                        putchar(va_arg(args, int));
                                        len++;
                                        break;
                                case 's':
                                        len += _puts(va_arg(args, char *));
                                        break;
                                case '%':
                                        putchar('%');
                                        len++;
                                        break;
                                default:
                                        putchar('%');
                                        putchar(*format);
                                        len += 2;
                                        break;
                        }
                }
                else
                {
                        putchar(*format);
                        len++;
                }
                format++;
        }

        va_end(args);

        return (len);
}