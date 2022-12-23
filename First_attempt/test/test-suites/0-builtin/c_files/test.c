#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// #define EXIT_STAT 98

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 1;
    /*Creating child process*/
    pid_t pid = fork();

    /*Argument array with executable at index 0*/
    // int sarg = atoi(argv[2]);
    char *sargv[] = {argv[1], argv[2], NULL};

    if (pid == -1)
        return (1);
    /*If successfully created*/
    if (pid == 0)
    {
        if (execve(sargv[0], sargv, NULL) == -1)
            perror("failed");
    }
    else
    {
        wait(NULL);
        printf("Done\n");
    }
    return 0;
}