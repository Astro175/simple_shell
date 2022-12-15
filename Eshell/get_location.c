#include "main.h"

/**
 * get_location-gets the location of the environment variable
 * @command: command passed
 * Returns: character pointer
 */

char *get_location(char *command)
{
    char *path, *path_copy, *path_token;
    path = getenv("PATH");
    path_copy = strdup(path);
    command_length = strlen(command);

    path_token = strtok(path_copy, ":");

}
