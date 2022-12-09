
# ALX Simple Shell Team Project

This is a team project in the ALX software engineering programme on creating
our own custom shell. Our shell is called shl
## Project was completed using
* C Programming language
* Betty linter
* Shell
## General Requirements for this project
* All files were compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All files should end with a new line
* Shell should not have any memory leaks
* No more than 5 functions per file
* All header files contained include guarded
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
## Description

shl is a simple UNIX command interpreter that reads commands from either a file or
the standard inputs and executes them. 
## How shl works

* Prints a prompt and waits for a command from the user
* Creates a child process in which the command is checked
* Checks for built-ins, aliases in the PATH, and local executable programs
* The child process is replaced by the command, which accepts arguments
* When the command is done, the program returns to the parent process and prints the prompt
* The program is ready to receive a new command
* To exit: press Ctrl-D or enter "exit" (with or without a status)
* Works also in non interactive mode

## Compilation Process

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shl
```


## Invocation
Usage: shl [filename]

To invoke shl, compile all .c files in the repository and run the resulting executable.

shl can be invoked both interactively and non-interactively. If shl is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example :

```http
$ echo "echo 'hello'" | ./shl
'hello'
$
```

If shl is invoked with standard input connected to a terminal (determined by isatty(3)), an interactive shell is opened. When executing interactively, shl displays the prompt $ when it is ready to read a command.

Example:

```http
$ cat test
echo 'hello'
$ ./shl test
'hello'
$
```


## Environment

Upon invocation, shl receives and copies the environment of the parent process in which it was executed. This environment is an array of name-value strings describing variables in the format NAME=VALUE. A few key environmental variables are:

## Home

The home directory of the current user and the default directory argument for the cd builtin command.

```bash
$ echo "echo $HOME" | ./shl
/home/projects
```


## PWD
The current working directory as set by the cd command.
```bash
$ echo "echo $PWD" | ./shl
/home/projects/alx/simple_shell
```
## OLDPWD

The previous working directory as set by the cd command.

```bash
$ echo "echo $OLDPWD" | ./shl
/home/projects/alx/printf
```

## PATH

A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

```bash
$ echo "echo $PATH" | ./shl
/home/projects/.cargo/bin:/home/projects/.local/bin:/home/projects/.rbenv/plugins/ruby-build/bin:/home/projects/.rbenv/shims:/home/projects/.rbenv/bin:/home/projects/.nvm/versions/node/v10.15.3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/projects/.cargo/bin:/home/projects/workflow:/home/projects/.local/bin
```
## Command Execution

After receiving a command, shl tokenizes it into words using " " as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. shl then proceeds with the following actions:

* If the first character of the command is neither a slash (\) nor dot (.), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.

* If the first character of the command is none of a slash (\), dot (.), nor builtin, hsh searches each element of the PATH environmental variable for a directory containing an executable file by that name.

* If the first character of the command is a slash (\) or dot (.) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.


## Exit Status

shl returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.

If a command is not found, the return status is 127; if a command is found but is not executable, the return status is 126.

All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).


## Signals

While running in interactive mode, shl ignores the keyboard input Ctrl+c. Alternatively, an input of end-of-file (Ctrl+d) will exit the program.

User hits Ctrl+d in the third line

```bash
$ ./shl
$ ^C
$ ^C
$
```

## Variable Replacement

shl interprets the $ character for variable replacement.
## $ENV VARIABLE

ENV_VARIABLE is substituted with its value.
Example:

```bash
$ echo "echo $PWD" | ./shl
/home/projects/alx/simple_shell
```


## $?
? is substitued with the return value of the last program executed.
Example:

```bash
$ echo "echo $?" | ./shl
0
```


## $$

The second $ is substitued with the current process ID.

Example:

```bash
$ echo "echo $$" | ./shl
5680
## Comments

shl ignores all words and characters preceeded by a # character on a line.

Example:

```bash
$ echo "echo 'hello' #this will be ignored!" | ./shl
'hello'
```
## Operators

shl specially interprets the following operator characters:

; - Command separator

Commands separated by a ; are executed sequentially.

Example:

```bash
$ echo "echo 'hello' ; echo 'world'" | ./shl
'hello'
'world'
```

### && - AND logical operator

```bash 
command1 && command2: command2 is executed if, and only if, command1 returns an exit status of zero.
```

Example: 

```bash
$ echo "error! && echo 'hello'" | ./shl
./shl: 1: error!: not found
$ echo "echo 'all good' && echo 'hello'" | ./shl
'all good'
'hello'
```
### || - OR logical operator

command1 || command2: command2 is executed if, and only if, command1 returns a non-zero exit status.

Example:

```bash
$ echo "error! || echo 'but still runs'" | ./shl
./shl: 1: error!: not found
'but still runs'
```

The operators && and || have equal precedence, followed by ;
## shl Built-in Commands

#### cd

* Usage: cd [DIRECTORY]
* Changes the current directory of the process to DIRECTORY
* If no argument is given, the command is interpreted as cd $HOME
* If the argument - is given, the command is interpreted as cd $OLDPWD and the pathname of the new working directory is printed to standad output.
* If the argument, -- is given, the command is interpreted as cd $OLDPWD but the pathname of the new working directory is not printed.
* The environment variables PWD and OLDPWD are updated after a change of directory

Example:

```bash
$ ./shl
$ pwd
/home/projects/alx/simple_shell
$ cd ../
$ pwd
/home/projects/alx
$ cd -
$ pwd
/home/projects/alx/simple_shell
```

#### alias

* Usage: alias [NAME[='VALUE'] ...]
* Handles aliases.
* alias: Prints a list of all aliases, one per line, in the form NAME='VALUE'
* alias NAME [NAME2 ...]: Prints the aliases NAME, NAME2, etc. one per line, in the form NAME='VALUE'
* alias NAME='VALUE' [...]: Defines an alias for each NAME whose VALUE is given. If name is already an alias, its value is replaced with VALUE

Example:

```bash
$ ./shl
$ alias show=ls
$ show
AUTHORS            builtins_help_2.c  errors.c         linkedlist.c        shell.h       test
README.md          env_builtins.c     getline.c        locate.c            hsh
alias_builtins.c   environ.c          helper.c         main.c              split.c
builtin.c          err_msgs1.c        helpers_2.c      man_1_simple_shell  str_funcs1.c
builtins_help_1.c  err_msgs2.c        input_helpers.c  proc_file_comm.c    str_funcs2.c
```

#### exit
* Usage: exit [STATUS]
* Exits the shell.
* The STATUS argument is the integer used to exit the shell.
* If no argument is given, the command is interpreted as exit 0.

Example:

```bash
$ ./shl
$ exit
```

#### env

* Usage: env
* Prints the current environment.

Example:

```bash
$ ./shl
$ env
NVM_DIR=/home/projects/.nvm
...
```

#### setenv

* Usage: setenv [VARIABLE] [VALUE]
* Initializes a new environment variable, or modifies an existing one.
* Upon failure, prints a message to stderr

Example:

```bash
$ ./shl
$ setenv NAME Poppy
$ echo $NAME
Poppy
```

#### unsetenv

* Usage: unsetenv [VARIABLE]
* Removes an environmental variable.
* Upon failure, prints a message to stderr.

Example: 
```bash
$ ./shl
$ setenv NAME Poppy
$ unsetenv NAME
$ echo $NAME

$
```
## What we learned

* How a shell works and finds commands
* Creating, forking and working with processes
* Executing a program from another program
* Handling dynamic memory allocation in a large program
* Pair programming and team work
* Building a test suite to check our own code

## Authors

AJAYI PRECIOUS DAVID
* [Github](https://github.com/Astro175)
* [Twitter](https://twitter.com/DaveMic00840181)
* [LinkedIn](https://https://www.linkedin.com/in/ajayi-precious-438a2122a/)

Ayobami Alaran A.
* [Github](https://github.com/Ayobami6)
