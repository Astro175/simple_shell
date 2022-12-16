#include "main.h"

/**
  * main - Building a simple shell
  * @ac : The number of arguments passed
  * argv: parameters passed
  */

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr, *lineptr_copy;
    const char *delim = " \n";
	size_t n = 0;
    ssize_t nchars_read;
    int i;
   /*number of characters the user typed*/
    int num_tokens = 0;
    char *token;    

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
        /* Splits strings into words */
        token = strtok(lineptr, delim);
        /* Determining how many tokens are there */
        while(token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;
        /* Allocating space for the array of strings */
        argv = malloc(sizeof(char) * num_tokens);
        /* Store Each string in the argv array */
        token = strtok(lineptr_copy, delim);

        for(i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;
        /* Execute the commands */
        execmd(argv);
            
		printf("%s", lineptr);
        
	
	}
	/* Frees up allocated space */
    free(lineptr);
    free(lineptr_copy);
    free(argv);
	return (0);
	}

