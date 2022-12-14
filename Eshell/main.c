#include "main.h"

/**
  * main - Building a simple shell
  * @ac : The number of arguments passed
  * argv: parameters passed
  */

int main(int ac, char **argv)
{
	char *prompt = "(Eshell) $ ";
	char *lineptr;
	size_t n = 0; 

		        /* declaring void variables */
	(void)ac; (void)argv;

			    /* create an infinite loop */
	while (1)
	{
		printf("%s", prompt);
		getline(&lineptr, &n, stdin);
		printf("%s\n", lineptr);

	/* free up allocated memory */
		free(lineptr);
	}
	
	return (0);
	}

