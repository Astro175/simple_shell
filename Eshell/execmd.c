#include "main.h"

/**
 * execmd- executes commands to the shell
 * @argv: array of strings
 */

void execmd(char **argv)
{
    char *command;

    /* Get the command */

    if(argv)
    {
        command = argv[0];

        /* execute the command with execve */

        if (execve(command, argv, NULL) == -1)
        {
            perror("Error: ");
        }
    }
}

