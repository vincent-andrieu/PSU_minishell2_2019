/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** double left redirect
*/

#include "my.h"
#include "mysh.h"

static char *get_input(char *end)
{
    char *input;
    char *output = my_strdup("");
    char *temp;

    while (true) {
        my_putstr("? ");
        input = get_cmd();
        if (!my_strcmp(end, input)) {
            free(input);
            break;
        }
        temp = output;
        output = my_strdupcat(3, output, input, "\n");
        free(temp);
    }
    return output;
}

int do_double_left_redirect(char ***env, int exit_value, char **parsed)
{
    char *cmd = my_strdupcat(2, parsed[0], parsed[4]);
    char *output = get_input(clear_redirect_path(parsed[3]));
    int fildes[2];
    int temp_dup = dup(0);

    if (temp_dup == -1 || pipe(fildes) == -1 || dup2(fildes[0], 0)
    || write(fildes[1], output, my_strlen(output)) == -1
    || close(fildes[1]) == -1) {
        free(cmd);
        free(output);
        return EXIT_ERROR;
    }
    free(output);
    exit_value = cmd_to_argv(cmd, env, exit_value);
    if (close(fildes[0]) == -1 || dup2(temp_dup, 0) == -1)
        return EXIT_ERROR;
    free(cmd);
    return exit_value;
}