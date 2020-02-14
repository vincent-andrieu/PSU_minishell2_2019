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
    char **argv = my_str_to_array("env", " \t", false);
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

Test(mysh, test_env_too_many_args)
{
    char **argv = my_str_to_array("env x", " \t", false);
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

Test(mysh, test_env_second_arg_test)
{
    char **argv = my_str_to_array("env test", " \t", false);
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

Test(mysh, test_env_permission_denied)
{
    char **argv = my_str_to_array("env /root", " \t", false);
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

Test(mysh, test_env_no_perm_folder)
{
    char **argv = my_str_to_array("env src", " \t", false);
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

Test(mysh, test_env_no_such_file_two)
{
    char **argv = my_str_to_array("env ..", " \t", false);
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