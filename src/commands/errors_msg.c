/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** put cd errors
*/

#include "my.h"
#include "mysh.h"

int put_command_not_found(char *cmd)
{
    my_put_error_str(cmd);
    my_put_error_str(": Command not found.\n");
    return EXIT_ERROR;
}

void put_permission_denied(char *path)
{
    my_put_error_str(path);
    my_put_error_str(": Permission denied.\n");
}

void put_too_many_args(char *cmd)
{
    my_put_error_str(cmd);
    my_put_error_str(": Too many arguments.\n");
}

void put_error_unalphanum(char *cmd, char *str)
{
    my_put_error_str(cmd);
    if ((str[0] >= '0' && str[0] <= '9') || (str[0] >= 'A' && str[0] <= 'Z')
    || (str[0] >= 'a' && str[0] <= 'z'))
        my_put_error_str(": Variable name must contain"
                        " alphanumeric characters.\n");
    else
        my_put_error_str(": Variable name must begin with a letter.\n");
}