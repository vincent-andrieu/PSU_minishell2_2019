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
    char **argv = my_str_to_array("unsetenv PWD", " \t", false);
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

Test(mysh, test_unsetenv_success_bad_name)
{
    char **argv = my_str_to_array("unsetenv lol", " \t", false);
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

Test(mysh, test_unsetenv_one_arg)
{
    char **argv = my_str_to_array("unsetenv", " \t", false);
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