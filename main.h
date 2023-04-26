#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

int _printf(const char *format, ...);
int print_int(int a, int len);
int print_char(va_list args, int len);
int print_str(va_list args, int len);
int count_formats(char *input);

#endif /* MAIN_H */
