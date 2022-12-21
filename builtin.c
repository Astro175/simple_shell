#include "main.h"

/**
 * shl_exit - exit the current process with a status
 * @args: parsed data
 * Return: the exit status
 */
int shl_exit()
{

	_puts("****************GOODBYE**************\n");
	return (0);
}

/**
 * shl_help - the cli help function
 * @argv: parsed arg
 * Return: 0
 */
int shl_help()
{

	_puts("Ayobami and David shell help page\n");

	_puts("Please use the man command for more info\n");

	return (1);
}
/**
 * builtin_call - double pointer function
 * @argv: data parsed
 * Return: -1 if function not found, 0 if sucessful,
 * 1 if not successful.
 */
int builtin_call(char **argv)
{
	int i;
	builtin_t builtin[] = {
		{"exit", shl_exit},
		{"help", shl_help},
		{NULL, NULL}
	};

	if (argv[0] == NULL)
		return (1);

	for (i = 0; builtin[i].name; i++)
		if (strcmp(argv[0], builtin[i].name) == 0)
			return (builtin[i].fp());
	return (shl_exec(argv));
}
