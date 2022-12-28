#include "main.h"

/**
 * split_string - Splits string
 * @argv: array of characters
 * @lineptr: strings
 * @delim: delimeter
 */

void split_string(char *lineptr, const char *delim, char ***argv)
{
	int num_tokens = 0;
	char *token;
	int i;

	/* Splits strings into words */
	token = strtok(lineptr, delim);

	/* Determining how many tokens are there */
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	/* Allocating space for the array of strings */
	*argv = malloc(sizeof(char*) * num_tokens);
	/* Store Each string in the argv array */
	token = strtok(lineptr, delim);

	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * strlen(token));
		strcpy((*argv)[i], token);
		token = strtok(NULL, delim);
	}
	(*argv)[i] = NULL;
}
