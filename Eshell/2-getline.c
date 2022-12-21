#include <stdio.h>
#include <stdlib.h>


/**
 * main - Prints a prompt and waits for the user, then displays it on the screen
 * Return: Always 0
 */

int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread;

	while(1)
	{
		nread = getline(&lineptr, &n, stdin);

		if (nread == -1)
		{
			break;
		}

		printf("%s", lineptr);
	}
	free(lineptr);

	return(0);
}
