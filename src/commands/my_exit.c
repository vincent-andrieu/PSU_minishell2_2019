/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** exit command
*/

#include "my.h"
#include "mysh.h"

static int print_error(char **argv)
{
    my_putstr(argv[0]);
    my_putstr(": Expression Syntax.\n");
    return EXIT_FAILURE;
}

int my_exit(char **argv, char ***env)
{
    int argc = get_argc(argv);
    int exit_value;

    if (argc > 2 || (argc == 2 && !my_str_isnum(argv[1])))
        return print_error(argv);
    my_cd(NULL, env);
    for (int i = 0; (*env)[i]; free((*env)[i]), i++);
    free(*env);
    exit_value = argc == 2 ? my_getnbr(argv[1]) : EXIT_SUCCESS;
    for (int i = 0; argv[i]; free(argv[i]), i++);
    free(argv);
    my_putstr("exit\n");
    exit(exit_value);
}