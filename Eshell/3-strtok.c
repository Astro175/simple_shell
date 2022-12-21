#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * split_string- breaks a string into tokens
 * str - string to words
 * Return: pointer to a character array
 */

char **split_string(char *str)
{
	char **words = NULL;
	int num_words = 0;

	char *token = strtok(str, " ");

	while(token != NULL)
	{
		num_words++;
		words = realloc(words, sizeof(char*) * num_words);
		words[num_words - 1] = malloc((strlen(token) + 1) * sizeof(char));
		strcpy(words[num_words - 1], token);

		token = strtok(NULL, " ");
	}

	words = realloc(words, (num_words + 1) * sizeof(char));
	words[num_words] = NULL;

	return words;
}

/**
 * main - Program that checks for strings
 * Return: Always 0
 */

int main(void)
{
	char str[] = "This is a string";
	char **words = split_string(str);
	int i;

	for (i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
	}

	for (i = 0; words[i] != NULL;  i++)
	{
		free(words[i]);
	}

	free(words);

	return (0);

}
