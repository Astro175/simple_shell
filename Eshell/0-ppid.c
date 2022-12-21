#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Prints the parent process ID
 * Return: Always 0
 */

int main(void)
{
	pid_t childpid;
	pid_t ppid;

	childpid = getpid();
	ppid = getppid();

	printf("%u\n", childpid);
	printf("%u\n", ppid);
	return (0);
}
