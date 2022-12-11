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
		i += _putfd(*str++, fd);
	}
	return (i);
}