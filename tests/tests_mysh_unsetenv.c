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

Test(mysh, test_unsetenv_success_one_param)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("unsetenv PWD")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_unsetenv_success_bad_name)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("unsetenv lol")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_unsetenv_one_arg)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("unsetenv")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}