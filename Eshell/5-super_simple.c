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
	while (1)
	{
		printf("$ ");
		char *command = NULL;
		size_t size = 0;
		int result = getline(&command, &size, stdin);

		if (result == -1)
		{
			fprintf(stderr, "Error reading command\n");
			return (-1);
		}

		char *token = strtok(command, " \n");

		if (token == NULL)
		{
			continue;
		}

		char *argv[1024];
		int i = 0;
		while((argv[i] = strtok(NULL, " \n")) != NULL)
		{
			i++;
		}
		argv[i] = NULL;


		pid_t pid = fork();

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
