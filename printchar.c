/**
* printchar - Prints a single character to stdout
* @c: The character to print
*
* Return: The number of characters printed
*/
int printchar(char c)
{
return (write(1, &c, 1));
}

/**
* printstr - Prints a string to stdout
* @str: The string to print
*
* Return: The number of characters printed
*/
int printstr(char *str)
{
return (write(1, str, strlen(str)));
}
