#include "main.h"

/**
 * shl_exec - executes the commands passed
 * @argv: string array
 * Return: -1 if sucessful, 0 if failed
 */
int shl_exec(char **argv)
{
	if (argv[0] == NULL)
		return (1);

	pid_t pid;
	int status;

	pid = fork();

	/*if creating child process failed.*/
	if (pid == -1)
		return (1);

	/*entering the child process to perform the execution*/
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Failed");
			return (0);
		}
	}

	else
	{
		do {
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
int shl_loop(void)
{
	size_t n;
	char *args = NULL;
	int status = 1;
	char **argv;
	ssize_t parsed = 0;

	while (status)
	{
		_puts("($) ");
		parsed = getline(&args, &n, stdin);
		/*Handling the EOF ctrl+D*/
		if (parsed == -1)
			return (-1);

		char *delim = " ";
		char **tokens = malloc(1024 * sizeof(char *));
		int i = 1;

		*(args + (_strlen(args) - 1)) = '\0';
		tokens[0] = strtok(args, delim);
		tokens[1] = NULL;
		status = shl_exec(tokens);
		free(tokens);
	}
}

/**
 * main - main
 * @argc: arg count
 * @argv: arg vector
 * Return: exit success
*/
int main(int argc, char **argv)
{

	shl_loop();

	return (EXIT_SUCCESS);
}
