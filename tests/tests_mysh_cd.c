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

Test(mysh, test_cd_success_one_arg)
{
    char **argv = my_str_to_array("cd", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_one_arg_no_env)
{
    char **argv = my_str_to_array("cd", " \t", false);
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

Test(mysh, test_cd_too_much_args)
{
    char **argv = my_str_to_array("cd 1 2 3", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_src)
{
    char **argv = my_str_to_array("cd src", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_home)
{
    char **argv = my_str_to_array("cd ~", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_no_env)
{
    char **argv = my_str_to_array("cd ~", " \t", false);
    char **env = my_str_to_array("LOL", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_last_dir_success)
{
    char **argv = my_str_to_array("cd src", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    argv = my_str_to_array("cd -", " \t", false);
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_last_dir_failure)
{
    char **argv = my_str_to_array("cd -", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_no_permission)
{
    char **argv = my_str_to_array("cd /root", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_bad_dir)
{
    char **argv = my_str_to_array("cd Makefile", " \t", false);
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}