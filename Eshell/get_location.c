#include "main.h"

/**
 * get_location-gets the location of the environment variable
 * @command: command passed
 * Returns: character pointer
 */

char *get_location(char *command)
{
    char *path, *path_copy, *path_token, *file_path;
    path = getenv("PATH");
    path_copy = strdup(path);
    command_length = strlen(command);
    int directory_length;


    path_token = strtok(path_copy, ":");
    /**Allocate space for the command and directory length*/
    directory_length = strlen(path_token);
    file_path = malloc(command_length + directory_length + 2);
    /* Copy result from path_token and append a forward slash and the command */
    strcpy(file_path, path_token);
    strcat(file_path, "/");
    strcat(file_path, command);
    strcat(file_path, "\0");



}
