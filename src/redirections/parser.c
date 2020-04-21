/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** parser
*/

#include <stdio.h>
#include <fcntl.h>
#include "my.h"
#include "mysh.h"

static int open_file(bool is_right, char const *path, int *fd, int const size)
{
    if (is_right)
        if (size == 4)
            *fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0664);
        else if (size == 3)
            *fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0664);
        else
            return EXIT_ERROR;
    else
        if (size == 3)
            *fd = open(path, O_RDWR);
        else
            return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int do_redirects(char **parsed, int *fd, int const size)
{
    char *path = clear_redirect_path(parsed[size - 1]);

    if (open_file(!my_strcmp(parsed[1], ">"), path, fd, size) == EXIT_ERROR)
        return EXIT_ERROR;
    if (*fd == -1)
        return EXIT_ERROR;
    if (dup2(*fd, !my_strcmp(parsed[1], ">")) == -1)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int manage_cmd_type(char *cmd, char ***env, int exit_value, char **parsd)
{
    int size = 0;
    int cmd_type = manage_parser_errors(parsd, &size);
    int temp_dup = parsd[1] ? dup(!my_strcmp(parsd[1], ">")) : -1;
    int fd;

    if (cmd_type != EXIT_SUCCESS)
        return cmd_type == EXIT_ERROR ? EXIT_FAILURE
        : cmd_to_argv(cmd, env, exit_value);
    if (size == 4 && !my_strcmp(parsd[1], "<")) {
        close(temp_dup);
        return do_double_left_redirect(env, exit_value, parsd);
    }
    if (temp_dup == -1 || do_redirects(parsd, &fd, size) == EXIT_ERROR)
        return EXIT_ERROR;
    exit_value = cmd_to_argv(parsd[0], env, exit_value);
    if (dup2(temp_dup, !my_strcmp(parsd[1], ">")) == -1 || close(fd) == -1)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

char *clear_redirect_path(char *path)
{
    int i = 0;

    for (; path[0] == ' ' || path[0] == '\t'; path++);
    for (; path[i] != ' ' && path[i] != '\0'; i++);
    path[i] = '\0';
    return path;
}

int parser(char ***env, int exit_value, char *cmd)
{
    char **parsed = my_str_to_array(cmd, "<>", true);

    exit_value = manage_cmd_type(cmd, env, exit_value, parsed);
    free_tab(parsed);
    return exit_value;
}