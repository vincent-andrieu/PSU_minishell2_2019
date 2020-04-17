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

int split_semicolons(char ***env, int exit_value)
{
    char *cmd = get_cmd();
    char **commands = my_str_to_array(cmd, ";", false);

    if (cmd != NULL && cmd[0] == '\0')
        return exit_value;
    else if (commands == NULL) {
        exit(0);
        free(cmd);
        my_cd(NULL, NULL);
        for (int i = 0; (*env)[i]; free((*env)[i]), i++);
        free(*env);
        if (isatty(0))
            my_putstr("exit\n");
        exit(exit_value);
    }
    free(cmd);
    for (int i = 0; commands[i] != NULL; i++)
        if (!is_only_spaces(commands[i]))
            exit_value = parser(env, exit_value, commands[i]);
    free_tab(commands);
    return exit_value;
}