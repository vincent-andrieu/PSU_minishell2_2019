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

int cmd_to_argv(char *cmd, char ***env, int exit_value)
{
    char **argv = my_str_to_array(cmd, " \t", false);

    if (argv == NULL)
        return exit_value;
    exit_value = interpretor(argv, env, exit_value);
    for (int i = 0; argv[i]; free(argv[i]), i++);
    free(argv);
    return exit_value;
}