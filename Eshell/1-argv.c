#include <stdio.h>

/**
 * main - Prints the number of arguments in a program
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int i;

	for(i = 0; i < argc; i++)
	{
		printf("argv[%d] is %s\n", i, argv[i]);
	}
	return (0);
}
