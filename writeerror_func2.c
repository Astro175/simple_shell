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
