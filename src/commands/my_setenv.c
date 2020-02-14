/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** set env
*/

#include "my.h"
#include "mysh.h"

int edit_env(char **var, char *name)
{
    int i = 0;
    char *temp_var = *var;

    for (; (*var)[i] != '='; i++);
    (*var)[i + 1] = '\0';
    *var = my_strndup(*var, my_strlen(*var) + my_strlen(name));
    free(temp_var);
    if (*var == NULL)
        return EXIT_ERROR;
    my_strcat(*var, name);
    return EXIT_SUCCESS;
}

int create_env_var(char ***env, char *name, char *value)
{
    int i = 0;
    char **temp_env = *env;

    *env = env_dup(*env, 1);
    for (int i = 0; temp_env[i]; free(temp_env[i]), i++);
    free(temp_env);
    for (; (*env)[i] != NULL; i++);
    (*env)[i] = my_strndup(name, my_strlen(name) + my_strlen(value));
    if ((*env)[i] == NULL)
        return EXIT_ERROR;
    my_strcat((*env)[i], value);
    return EXIT_SUCCESS;
}

int my_setenv(char **argv, char ***env)
{
    int argc = get_argc(argv);

    if (argc > 3) {
        put_too_many_args(argv[0]);
        return EXIT_FAILURE;
    }
    if (argc == 1)
        return my_env(argv, env);
    if (argc >= 2 && !my_str_isalphanum(argv[1])) {
        put_error_unalphanum(argv[0], argv[1]);
        return EXIT_FAILURE;
    }
    argv[1] = add_name_equal(argv[1]);
    if (argv[1] == NULL)
        return EXIT_ERROR;
    for (int i = 0; (*env)[i]; i++)
        if (!my_strncmp((*env)[i], argv[1], my_strlen(argv[1])))
            return edit_env(&((*env)[i]), argc == 3 ? argv[2] : NULL);
    return create_env_var(env, argv[1], argc == 3 ? argv[2] : NULL);
}