#ifndef SHELL_H_
#define SHELL_H_

#include <unistd.h>

/* Write functions prototypes*/
int _putchar(char c);
void _puts(char *str);

/* Write error functions prototypes*/
int _eputchar(char c);
void _eputs(char *str);
int _putcfd(char c, int fd);
int _putsfd(char *str, int fd);

#endif
