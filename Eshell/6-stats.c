#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * main - Program that works like the which command
 * Return: 0;
 */

int main(int ac, **av)
{
	char *path;
	char *path_element;
	char *file_path;
	struct stat st;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s filename ... \n", av[0]);
		return (1);
	}

	path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "Path environ not set.\n");
		return (1);
	}

	path_element = strtok(path, ":");
	

	while(path_element != NULL)
	{
		int i;

		for(i = 1; i < ac; i++)
		{
			file_path = malloc(strlen(path_element) + strlen(av[i]) + 2);

			if (file_path == NULL)
			{
				fprintf(stderr, "Memory allocation failed\n");
				return (1);
			}
			sprintf(file_path, %s/&s, path_element, av[i]);

			

