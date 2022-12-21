#include "main.h"

/**
 * strtok- Splits a string into words, delimiters are ignored
 * @str: string to be split
 * @d: delimiter
 * Return: a pointer to an array of strings or NULL on failure
 */

char **strtok(char *str, char *d)
{
    /* Declaring of variables */

    int i, j, k, numwords = 0;
    char **s;

    /* Checks if input string is NULL or 0 */
    if (str == NULL || str[0] == 0)
        return (NULL);

    /* Checks if delimiter is empty and assigns a default value */
    if (!d)
        d = " ";
    /* For loop that checks if we don't have a strings of delimiters */
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!is_delim(str[i], d) && (is_delim(str[i+1], d) || !str[i + 1]))
            numwords++;
    }
    if (numwords == 0)
        return (NULL);

    /* Allocating space for the array of pointers */

    s = malloc((numwords + 1) * sizeof(char));
    
    if(s == NULL)
        return (NULL);

