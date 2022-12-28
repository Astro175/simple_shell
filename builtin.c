#include "main.h"

/**
 * shl_exit - exit the current process with a status
 * Return: the exit status
 */
int shl_exit(void)
{

	_puts("****************GOODBYE**************\n");
	return (0);
}

/**
 * shl_help - the cli help function
 * Return: 0
 */
int shl_help(void)
{

	_puts("Ayobami and David shell help page\n");

	_puts("Please use the man command for more info\n");

	return (1);
}
/**
 * builtin_call - function that execute the buitin commands
 * @argv: data parsed
 * @av: array of strings from the command line.
 * Return: -1 if function not found, 0 if sucessful,
 * 1 if not successful.
 */
int builtin_call(char **argv, char **av)
{

	int i;

	builtin_t builtin[] = {
		{"exit", shl_exit},
		{"help", shl_help},
		{NULL, NULL}
	};
	/*If arg 1 is null prompt again*/
	if (argv[0] == NULL)
		return (1);
	/*Checking if the parsed command is the same with builtin command name*/
	for (i = 0; builtin[i].name; i++)
		if (strcmp(argv[0], builtin[i].name) == 0)
			return (builtin[i].fp());
	/*If the command not in buitin call exec on the command executable*/
	return (shl_exec(argv, av));
}
