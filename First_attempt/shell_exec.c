#include "main.h"

/**
 * shl_exec - executes the commands passed
 * @argv: string array
 * @av: Arrayof strings
 * Return: -1 if sucessful, 0 if failed
 */
int shl_exec(char **argv, char **av)
{
	pid_t pid;

	int status;

	/*If no arg is parsed to the prompt return 1 as a status then reprompt*/
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
			/*Putting the name of the shell ran from the commandline stderr*/
			perror(av[0]);
			return (0);
		}
	}
	/*Parent process waiting for the child*/
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
