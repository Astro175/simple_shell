#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Eexecutes a command
 * Return: Always 0
 */

int main(void)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			char *argv[] = {"ls","-l", "/tmp", NULL};
			execve("/bin/ls", argv, NULL);
		}
		else if(pid > 0)
		{
			int status;

			wait(&status);
		}
		else
		{
			perror("fork failed");
			return (1);
		}
	}
	return (0);
	}
