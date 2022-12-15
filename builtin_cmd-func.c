#include "main.h"
/**
 * builtin_call - double pointer function
 * @data: data parsed
 * Return: -1 if function not found, 0 if sucessful,
 * 1 if not sucessful.
 */
int builtin_call(shl_t *data)
{
	int i;

	builtin_t builtin[] = {
		{"exit", shl_exit},
		{"env", shl_env},
		{"help", shl_help},
		{"history", shl_history},
		{"setenv", shl_setenv},
		{"unsetenv", shl_unsetenv},
		{"cd", shl_cd},
		{"alias", shl_alias},
		{NULL, NULL}};

	for (i = 0; builtin[i].name; i++)
		if (_strcmp(data->argv[0], builtin[i].name) == 0)
			return (builtin[i].fp(data->argv));
	return (-1);
}

/*Still working on this*/
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

int shl_help(shl_t *data)
{
	int i;

	_puts("Ayobami and David shell help page\n");

	_puts("Please use the man command for more info\n");

	return (0);
}
