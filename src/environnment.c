/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** manage environnment
*/

#include <stdlib.h>
#include "my.h"

int get_argc(char **argv)
{
    int i = 0;

    for (; argv != NULL && argv[i] != NULL; i++);
    return i;
}

char **env_dup(char **env, int more)
{
    char **new;
    int size = 0;

    if (env == NULL)
        return NULL;
    for (; env[size]; size++);
    new = malloc(sizeof(char *) * (size + 1 + more));
    if (new == NULL)
        return NULL;
    for (int i = 0; env[i]; i++) {
        new[i] = my_strdup(env[i]);
        if (new[i] == NULL)
            return NULL;
    }
    for (int i = size; i <= size + more; i++)
        new[i] = NULL;
    return new;
}

char *add_name_equal(char *name)
{
    char *new_name = my_strndup(name, my_strlen(name) + 1);

    if (new_name == NULL)
        return NULL;
    free(name);
    my_strcat(new_name, "=");
    return new_name;
}

bool is_term_exist(char **env)
{
    int i = 0;

    for (; env[i] && my_strncmp(env[i], "TERM=", 5); i++);
    return env[i] == NULL ? false : true;
}