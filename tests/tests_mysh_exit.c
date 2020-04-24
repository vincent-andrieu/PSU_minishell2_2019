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

Test(mysh, test_exit_success_one_arg)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("exit")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_exit_too_many_args)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("exit 1 2")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_exit_arg_not_number)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("exit lol")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_exit_with_num)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("exit 0")), 0);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}