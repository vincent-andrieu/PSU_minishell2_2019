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
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd")),
        EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_one_arg_no_env)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_too_much_args)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd 1 2 3")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_src)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd src")),
        EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_home)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd ~")),
        EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_no_env)
{
    char **env = my_str_to_array("LOL", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd ~")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_last_dir_success)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd src")),
        EXIT_SUCCESS);
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd -")),
        EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_last_dir_failure)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd -")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_no_permission)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd /root")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_cd_bad_dir)
{
    char **env = my_str_to_array("OLDPWD=/home PWD=/home HOME=/home",
    " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS, my_strdup("cd Makefile")),
        EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}