/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** my cd
*/

#include "my.h"
#include "mysh.h"

static char *check_flags(char *path, char **env, char *old_pwd)
{
    char *new_path = my_strdup(path);
    int var_len;
    int k = 0;

    if (!my_strcmp(path, "-")) {
        free(new_path);
        return my_strdup(old_pwd == NULL ? "" : old_pwd);
    }
    if (!my_strcmp(path, "~")) {
        free(new_path);
        var_len = my_strlen("HOME=");
        for (; env[k] && my_strncmp(env[k], "HOME=", var_len); k++);
        if (env[k] == NULL)
            return NULL;
        new_path = my_strndup(env[k] + var_len,
                    my_strlen(env[k] + var_len) + my_strlen(path + 1));
        my_strcat(new_path, path + 1);
    }
    return new_path;
}

static int edit_env_cd(char *cmd, char ***env, char *var)
{
    char *my_av[4];
    int exit_value = EXIT_SUCCESS;

    my_av[0] = cmd;
    my_av[1] = my_strdup(var);
    my_av[2] = getcwd(NULL, 0);
    if (my_av[2] == NULL)
        return EXIT_ERROR;
    my_av[3] = NULL;
    exit_value = my_setenv(my_av, env);
    free(my_av[1]);
    free(my_av[2]);
    return exit_value;
}

static int move_current_dir(char **old_pwd, char *path)
{
    free(*old_pwd);
    *old_pwd = getcwd(NULL, 0);
    if (*old_pwd == NULL)
        return EXIT_ERROR;
    if (chdir(path) == -1) {
        put_permission_denied(path);
        free(path);
        return EXIT_FAILURE;
    }
    free(path);
    return EXIT_SUCCESS;
}

int my_cd(char **argv, char ***env)
{
    static char *oldpwd = NULL;
    int exit_value = EXIT_FAILURE;
    char *path = argv != NULL ? check_flags(get_argc(argv) == 2 ? argv[1] : "~",
                                            *env, oldpwd) : NULL;

    exit_value = check_cd_errors(argv, path);
    if (exit_value != EXIT_SUCCESS) {
        if (argv == NULL)
            free(oldpwd);
        free(path);
        return exit_value;
    }
    if (edit_env_cd(argv[0], env, "OLDPWD") != EXIT_SUCCESS)
        return EXIT_ERROR;
    exit_value = move_current_dir(&oldpwd, path);
    if (exit_value != EXIT_SUCCESS)
        return exit_value;
    return edit_env_cd(argv[0], env, "PWD");
}