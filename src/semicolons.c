/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** semicolons manager
*/

#include "my.h"
#include "mysh.h"

static bool is_only_spaces(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ' && str[i] != '\t')
            return false;
    return true;
}

static int travel_commands(char **commands, char ***env, int exit_value)
{
    for (int i = 0; commands[i] != NULL; i++)
        if (!is_only_spaces(commands[i]))
            exit_value = redirections_parser(env, exit_value, commands[i]);
    return exit_value;
}

int split_semicolons(char ***env, int exit_value, char *cmd)
{
    char **commands = my_str_to_array(cmd, ";", false);

    if (cmd != NULL && cmd[0] == '\0')
        return exit_value;
    else if (commands == NULL) {
        free(cmd);
        my_cd(NULL, NULL);
        if (env != NULL) {
            for (int i = 0; (*env)[i]; free((*env)[i]), i++);
            free(*env);
        }
        if (isatty(0))
            my_putstr("exit\n");
        exit(exit_value);
    }
    free(cmd);
    exit_value = travel_commands(commands, env, exit_value);
    free_tab(commands);
    return exit_value;
}