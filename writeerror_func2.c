#include "main.h"

/**
 * print_error - prints an error message
 * @data: param of shl_t data type
 * @dest: string for the error message
 */
void print_error(shl_t *data, char *dest)
{
	_eputs(data->file_name);
	_eputs(": ");
	print_d(data->err_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(data->argv[0]);
	_eputs(": ");
	_eputs(dest);
}

/**
 * _erratoi - converts strings to long long integer
 * @s: parsed string
 * Return: 0 or -1
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > __INT_MAX__)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
