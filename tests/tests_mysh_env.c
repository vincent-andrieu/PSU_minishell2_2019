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

Test(mysh, test_env_success)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("env")),
        EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_env_too_many_args)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("env x")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_env_second_arg_test)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("env test")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_env_permission_denied)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("env /root")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_env_no_perm_folder)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("env src")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_env_no_such_file_two)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("env ..")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}