#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

/**
 * main - A super simple shell
 * Return: Always 0
 */

int main(void)
{
	char *argv[1023];
	pid_t pid;
	int i, result;
	char *command;
	char *token;
	size_t size;
	while (1)
	{
		printf("$ ");
		command = NULL;
		size = 0;
		result = getline(&command, &size, stdin);

		if (result == -1)
		{
			fprintf(stderr, "Error reading command\n");
			return (-1);
		}

		token = strtok(command, " \n");

		if (token == NULL)
		{
			continue;
		}

		i = 0;
		while((argv[i] = strtok(NULL, " \n")) != NULL)
		{
			i++;
		}
		argv[i] = NULL;


		pid = fork();

		if (pid == 0)
		{
			execve(token, argv, NULL);
		}
		else if (pid > 0)
			wait(NULL);
		else
			perror("Failed to fork process");
	}
	return (0);
}
