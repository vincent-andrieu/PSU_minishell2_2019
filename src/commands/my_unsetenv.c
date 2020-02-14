/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** unsetenv command
*/

#include "my.h"
#include "mysh.h"

static void put_too_few_args(char *cmd)
{
    my_putstr(cmd);
    my_putstr(": Too few arguments.\n");
}

static void delete_index(char **tab, int index)
{
    free(tab[index]);
    for (int i = index; tab[i] != NULL; i++)
        tab[i] = tab[i + 1];
}

int my_unsetenv(char **argv, char ***env)
{
    int argc = get_argc(argv);

    if (argc <= 1) {
        put_too_few_args(argv[0]);
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc; i++) {
        argv[i] = add_name_equal(argv[i]);
        if (argv[i] == NULL)
            return EXIT_ERROR;
        for (int k = 0; (*env)[k]; k++)
            if (!my_strncmp((*env)[k], argv[i], my_strlen(argv[i]))) {
                delete_index(*env, k);
                break;
            }
    }
    return EXIT_SUCCESS;
}