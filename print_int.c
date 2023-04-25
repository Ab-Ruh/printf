#include <unistd.h>

/**
 * print_int - Prints integers
 * @a: int input
 * @b: int input number of characters printed
 * Return: The number of characters printed
 */
int print_int(int a, int b)
{
	char c;

	if (a < 0)
	{
		write(1, "-", 1);
		a = -1 * a;
	}
	if (a > 9)
	{
		print_int(a / 10, b);
	}
	c = '0' + (a % 10);
	b += write(1, &c, 1);
	return (b);
}
