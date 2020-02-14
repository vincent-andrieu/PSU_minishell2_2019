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
    char **argv = my_str_to_array("setenv", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_success_two_args)
{
    char **argv = my_str_to_array("setenv mdr", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_success_three_args)
{
    char **argv = my_str_to_array("setenv mdr lol", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_four_args)
{
    char **argv = my_str_to_array("setenv mdr lol hehe", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_no_first_letter_alpha)
{
    char **argv = my_str_to_array("setenv =mdr lol", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_no_alphanum)
{
    char **argv = my_str_to_array("setenv m=dr lol", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_edit_path_null)
{
    char **argv = my_str_to_array("setenv OLDPWD", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_setenv_edit_path)
{
    char **argv = my_str_to_array("setenv OLDPWD /", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}