#include "main.h"

/**
 * convert_number - converts a number
 * @num: parsed number
 * @base: parsed number base
 * @flags: arg flag
 * Return: a string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *str;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';

	do {
		*--str = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--str = sign;
	return (str);
}

/**
 * print_list - prints all values of a list
 * @node: node for the list
 * Return: the size of the list
 */
size_t print_list(const list_t *node)
{
	size_t i = 0;

	while (node)
	{
		_puts(convert_number(node->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(node->s ? node->s : "(nil)");
		_puts("\n");
		node = node->next;
		i++;
	}
	return (i);
}
