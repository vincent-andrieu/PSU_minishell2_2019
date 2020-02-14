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
    char **argv = my_str_to_array("exit", " \t", false);
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

Test(mysh, test_exit_too_many_args)
{
    char **argv = my_str_to_array("exit 1 2", " \t", false);
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

Test(mysh, test_exit_arg_not_number)
{
    char **argv = my_str_to_array("exit lol", " \t", false);
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

Test(mysh, test_exit_with_num)
{
    char **argv = my_str_to_array("exit 0", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), 0);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}