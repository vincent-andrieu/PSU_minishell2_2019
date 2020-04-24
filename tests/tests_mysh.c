/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** criterion tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "mysh.h"

Test(mysh, test_mysh_null_get_argc)
{
    cr_assert_eq(get_argc(NULL), 0);
}

Test(mysh, test_mysh_null_env_dup)
{
    cr_assert_eq(env_dup(NULL, 0) == NULL, 1);
}

Test(mysh, test_no_env_command)
{
    char **env = my_str_to_array("OLDPWD=no_old_pwd", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("this_is_not_a_command")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_launch_sigv)
{
    char **env = my_str_to_array("TERM=xterm PATH=.", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("./tests/my_segfault")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_launch_wrongarch)
{
    char **env = my_str_to_array("PATH=.", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("./tests/test_wrongarch")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_ls)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_dir)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("./src")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_command_not_found)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("this_command_is_not_found")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_root_dir)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("/root")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_no_permission)
{
    char **env = my_str_to_array("PATH=/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("./Makefile")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_no_argv)
{
    cr_assert_eq(split_semicolons(NULL, EXIT_SUCCESS, NULL), EXIT_SUCCESS);
}