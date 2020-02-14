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

Test(mysh, test_mysh_null_get_argc)
{
    cr_assert_eq(get_argc(NULL), 0);
}

Test(mysh, test_mysh_null_env_dup)
{
    cr_assert_eq(env_dup(NULL, 0) == NULL, 1);
}

Test(mysh, test_no_env_command)
{
    char **argv = my_str_to_array("this_is_not_a_command", " \t", false);
    char **env = my_str_to_array("OLDPWD=no_old_pwd", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_launch_sigv)
{
    char **argv = my_str_to_array("./tests/my_segfault", " \t", false);
    char **env = my_str_to_array("TERM=xterm PATH=.", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_launch_wrongarch)
{
    char **argv = my_str_to_array("./tests/test_wrongarch", " \t", false);
    char **env = my_str_to_array("PATH=.", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_ls)
{
    char **argv = my_str_to_array("ls", " \t", false);
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_SUCCESS);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_dir)
{
    char **argv = my_str_to_array("./src", " \t", false);
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_command_not_found)
{
    char **argv = my_str_to_array("this_command_is_not_found", " \t", false);
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_root_dir)
{
    char **argv = my_str_to_array("/root", " \t", false);
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_no_permission)
{
    char **argv = my_str_to_array("./Makefile", " \t", false);
    char **env = my_str_to_array("PATH=/bin", " \t", false);

    if (argv == NULL || env == NULL)
        return;
    cr_assert_eq(interpretor(argv, &env, EXIT_SUCCESS), EXIT_FAILURE);
    for (int i = 0; argv[i] != NULL; free(argv[i]), i++);
    free(argv);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_no_argv)
{
    cr_assert_eq(interpretor(NULL, NULL, EXIT_SUCCESS), EXIT_SUCCESS);
}