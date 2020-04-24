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

Test(mysh, test_semicolons_one)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls ; cd ..")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_semicolons_two)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls ; cd .. ; cd -")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_redirection_simple_right_success)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls > test_file ; rm test_file")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_redirection_simple_right_error_missing)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls > test_file >")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_redirection_simple_right_error_ambiguous)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls > test > ok")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_redirection_simple_right_error_null)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("> ls")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_redirection_simple_right_error_dir)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls > tests/")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_redirection_simple_left)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("cat < Makefile")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_redirection_double_right_success)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls >> test_file ; rm test_file")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_redirection_double_left_error)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls <<")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_many_redirections_error)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls > test >>")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_empty_line)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("         \t       ")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_multiple_redirections)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("<<<<<<<<<<<<<<<<")), EXIT_FAILURE);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_no_cmd)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("")), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_null_cmd)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        NULL), EXIT_SUCCESS);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_no_perm_redirection)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(split_semicolons(&env, EXIT_SUCCESS,
        my_strdup("ls > /root/test")), EXIT_ERROR);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_null_parsed)
{
    char **env = my_str_to_array("TERM=xterm PATH=.:/bin", " \t", false);

    if (env == NULL)
        return;
    cr_assert_eq(redirections_parser(&env, EXIT_SUCCESS, NULL), EXIT_ERROR);
    for (int i = 0; env[i] != NULL; free(env[i]), i++);
    free(env);
}

Test(mysh, test_null_argv)
{
    cr_assert_eq(cmd_to_argv(NULL, NULL, EXIT_ERROR), EXIT_ERROR);
}

Test(mysh, test_null_env_mysh_function)
{
    cr_assert_eq(mysh(NULL), EXIT_ERROR);
}

Test(mysh, test_clear_string)
{
    char *str = my_strdup("\ttest\t");

    clear_redirect_path(str);
    free(str);
}

Test(mysh, test_null_command_msg)
{
    null_command_error();
}