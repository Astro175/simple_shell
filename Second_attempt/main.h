#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void execmd(char **argv);
char *get_location(char *command);
void split_string(char *lineptr, const char *delim, char ***argv);
#endif
