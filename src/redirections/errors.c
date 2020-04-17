/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** parser errors
*/

#include <sys/stat.h>
#include "my.h"
#include "mysh.h"

static bool is_dir(char *path)
{
    struct stat st;
    
    if (stat(path, &st) == -1)
        return false;
    return S_ISDIR(st.st_mode);
}

int manage_parser_errors(char **parsed, int *size)
{
    for (; parsed[*size] != NULL; (*size)++);
    if (*size == 2 && !my_strcmp(parsed[0], ">") && my_strcmp(parsed[1], ">"))
        return null_command_error();
    if (*size == 1 && my_strcmp(parsed[1], ">"))
        return EXIT_FAILURE;
    if (*size == 2 || (*size == 3 && !my_strcmp(parsed[2], ">")))
        return missing_redirect_error();
    if ((*size > 4 && !my_strcmp(parsed[2], ">"))
    || (*size > 3 && my_strcmp(parsed[2], ">")))
        return ambiguous_error();
    if (is_dir(parsed[*size - 1]))
        return is_dir_error(parsed[*size - 1]);
    return EXIT_SUCCESS;
}