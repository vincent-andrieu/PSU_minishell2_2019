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

Test(mysh, test_setenv_success_one_arg)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("setenv")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_success_two_args)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("setenv mdr")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_success_three_args)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("setenv mdr lol")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_four_args)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("setenv mdr lol hehe")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_no_first_letter_alpha)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("setenv =mdr lol")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_no_alphanum)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("setenv m=dr lol")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_edit_path_null)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("setenv OLDPWD")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_edit_path)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("setenv OLDPWD /")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}