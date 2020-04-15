/*
** EPITECH PROJECT, 2019
** minishell 1
** File description:
** check wich command is enter
*/

#include "my.h"
#include "mysh.h"

int interpretor(char **argv, char ***env, int exit_value)
{
    if (get_argc(argv) <= 0)
        return exit_value;
    return choose_cmd_type(argv, env, exit_value);
}