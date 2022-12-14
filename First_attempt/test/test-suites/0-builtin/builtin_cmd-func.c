#include "main.h"
/**
 * builtin_call - double pointer function
 * @data: data parsed
 * Return: -1 if function not found, 0 if sucessful,
 * 1 if not sucessful.
 */
int builtin_call(char **argv)
{
	int i;

	builtin_t builtin[] = {
		{"exit", shl_exit},
		{"help", shl_help},
		{"history", shl_history},
		{NULL, NULL}};

	for (i = 0; builtin[i].name; i++)
		if (_strcmp(argv[0], builtin[i].name) == 0)
			return (builtin[i].fp(argv));
	return (-1);
}

/**
 * shl_exit - exit the current process with a status
 * @data: parsed data
 * Return: the exit status
 */
int shl_exit(shl_t *data)
{
	int exit_num;

	if (data->argv[1])
	{
		exit_num = _erratoi(data->argv[1]);
		if (exit_num == -1)
		{
			data->status = 2;
			print_error(data, "Denied");
			_eputs(data->argv[1]);
			_eputchar('\n');
			return (1);
		}
		data->err_num = _erratoi(data->argv[1]);
		return (-2);
	}
	data->err_num = -1;
	return (-2);
}

/**
 * shl_help - the cli help function
 * @data: parsed arg
 * Return: 0
 */
int shl_help(shl_t *data)
{
	int i;

	_puts("Ayobami and David shell help page\n");

	_puts("Please use the man command for more info\n");

	return (0);
}

/**
 * shl_history - print the command history
 * @data: parsed arg
 * Return: 0
 */
int shl_history(shl_t *data)
{
	print_list(data->history);
	return (0);
}
