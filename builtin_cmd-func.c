#include "main.h"

/*buitin strings*/
char *builtin_name[] = {"cd",
                        "help", "exit", "env", 
                        "history", "setenv", "alias",
                        "unsetenv"};
/**
 * builtin_func - double pointer function
*/
int (*buitin_func[])(char **) = {
	&shl_exit,
	&shl_help,
}
;

/*Still working on this*/
int shl_exit(char **args)
{
  return 0;
}

int shl_help(char **args)
{
  int i;
  _puts("Ayobami and David shell help page");
  _puts("Please use the man command for more info");
}
