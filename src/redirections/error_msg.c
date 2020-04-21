/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** error messages
*/

#include "my.h"
#include "mysh.h"

int ambiguous_error(void)
{
    my_put_error_str("Ambiguous output redirect.\n");
    return EXIT_ERROR;
}

int is_dir_error(char *path)
{
    my_put_error_str(path);
    my_put_error_str(": Is a directory.\n");
    return EXIT_ERROR;
}

int missing_redirect_error(void)
{
    my_put_error_str("Missing name for redirect.\n");
    return EXIT_ERROR;
}

int null_command_error(void)
{
    my_put_error_str("Invalid null command.\n");
    return EXIT_ERROR;
}