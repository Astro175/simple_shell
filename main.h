#ifndef SHELL_H_
#define SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*Macros*/
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct list - linked list structure
 * @num: number arg
 * @s: string
 * @next: next node
 */
typedef struct list
{
	int num;
	char *s;
	struct list *next;
} list_t;

/*builtin function structure*/
/**
 * struct builtin - object for builtin command
 * @name: name of the command argument
 * @fp: function pointer thats stores the algo for the functions to be called
 */
typedef struct builtin
{
	char *name;
	int (*fp)();
} builtin_t;

/**
 * struct shlObj - shell object
 * @arg: param arg
 * @argv: strings array
 * @file_name: filename
 * @err_count: error count
 * @status: returning status
 * @err_num: error number
 * @history: history list
 */
typedef struct shlObj
{
	char *arg;
	char **argv;
	char *file_name;
	unsigned int err_count;
	int status;
	int err_num;
	list_t *history;
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
int builtin_call(char **argv, char *av[]);
int shl_exit();
int shl_help();

/*Strings functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

/*More strings function*/
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char *_strdup(char *str);

/*List functions 1*/
char *convert_number(long int num, int base, int flags);
size_t print_list(const list_t *h);

/*Shell.c*/
int shl_exec(char **argv, char *av[]);

#endif
