#include "main.h"

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	return (write(2, &c, 1));
}

/**
 *_eputs - prints an input string to stderr
 * @str: the string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _putcfd - puts char to a specified file descriptor
 * @c: char passed
 * @fd: file descriptor
 * Return: returns 1 on success and negative if error
 */
int _putcfd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the file descriptor
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putsfd(str++, fd);
	}
	return (i);
}

/**
 * print_d - prints a decimal integer number
 * @num: parsed integer number
 * @fd: file descriptor to write to
 * Return: the count of number printed
 */
int print_d(int num, int fd)
{
	/*Initialize the function pointer with putchar*/
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	/* if the file descriptor is 2 or stderr no*/
	/* switch the __putchar to _eputchar function*/
	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (num < 0)
	{
		_abs_ = -num;
		__putchar('-');
		count++;
	}
	else
		_abs_ = num;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}
