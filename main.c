#include "main.h"

/**
  * main - Building a simple shell
  * @ac : The number of arguments passed
  * @argv: parameters passed
  * Return: Always 0
  */

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr, *lineptr_copy;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t nchars_read;  

	/* declaring void variables */
	(void)ac;

	/* create an infinite loop */
	while (1)
	{       
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting the shell...\n");
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);

		split_string(lineptr, delim, &argv);

		/* Execute the commands */
		execmd(argv);
		
	}

		/* Frees up allocated space */
	free(lineptr);
	free(lineptr_copy);
	return (0);
}
