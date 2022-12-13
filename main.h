#ifndef SHELL_H_
#define SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Write functions prototypes*/
int _putchar(char c);
void _puts(char *str);

/* Write error functions prototypes*/
int _eputchar(char c);
void _eputs(char *str);
int _putcfd(char c, int fd);
int _putsfd(char *str, int fd);

/*buitin cmd functions*/
int shl_exit(char **args);

#endif
