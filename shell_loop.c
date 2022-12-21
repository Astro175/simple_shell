#include "main.h"

/**
* shl_loop - shell loop for prompt
* @av: takes no arg
* * Return: -1 for EOF and 0 for exit, 1 repeat
*/
int shl_loop(char *av[])
{
	size_t n = 0;
	char *args = NULL;
	int status = 1;

	while (status)
	{
		int i = 1;
		ssize_t parsed = 0;
		char *delim = " ";
		/*Using null delim for commnds to take no args*/
		char *del = "\0";
		char **tokens = malloc(1024 * sizeof(char *));

		if (tokens == NULL)
		{
			free(tokens);
			return (0);
		}
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		parsed = getline(&args, &n, stdin);
		if (parsed == -1)
		{
			free(args);
			return (-1);
		}
		*(args + (_strlen(args) - 1)) = '\0';
		tokens[0] = strtok(args, del);
		tokens[1] = "gb";
		while (tokens[i])
		{
			tokens[i] = strtok(NULL, delim);
			i++;
		}
		tokens[i] = NULL;

		status = shl_exec(tokens, av);
		free(tokens);
	}
	return (EXIT_SUCCESS);
}
