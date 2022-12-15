#ifndef SHELL_H_
#define SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*builtin function structure*/
/**
 * struct builtin - object for builtin command
 * @name: name of the command argument
 * @fp: function pointer thats stores the algo for the functions to be called
 */
typedef struct builtin
{
	char *name;
	int (*fp)(char **args);
} builtin_t;

typedef struct shlObj
{
	char *arg;
	char **argv;
	char *file_name;
	unsigned int err_count;
	int status;
	int err_num;
	/*more incoming*/
} shl_t;

/* Write functions prototypes*/
int _putchar(char c);
void _puts(char *str);

/* Write error functions 1 prototypes*/
int _eputchar(char c);
void _eputs(char *str);
int _putcfd(char c, int fd);
int _putsfd(char *str, int fd);
int print_d(int num, int fd);

/* Write error functions 2 prototypes*/
void print_error(shl_t *data, char *dest);

/*buitin cmd functions*/
int builtin_call(shl_t *);
int shl_exit(shl_t *data);
int shl_help(shl_t *data);

/*Strings functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif
