#include "main.h"

/**
 * shl_exec - executes the commands passed
 * @argv: string array
 * Return: -1 if sucessful, 0 if failed
 */
int shl_exec(char **argv, char *av[])
{
	pid_t pid;

	int status;

	if (argv[0] == NULL)
	{
		return (1);
	}

	pid = fork();

	/*if creating child process failed.*/
	if (pid == -1)
		return (1);

	/*entering the child process to perform the execution*/
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(av[0]);
			return (0);
		}
	}

	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}

/**
 * shl_loop - shell loop for prompt
 * @void: takes no arg
 * Return: -1 for EOF and 0 for exit, 1 repeat
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
		/*Handling the EOF ctrl+D*/
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
		};
		tokens[i] = NULL;

		status = shl_exec(tokens, av);
		free(tokens);
	}
	return (EXIT_SUCCESS);
}

/**
 * main - main
 * @argc: arg count
 * @argv: arg vector
 * Return: exit success
 */
int main(int argc, char *argv[])
{
	(void)(argc);

	shl_loop(argv);

	return (EXIT_SUCCESS);
}
