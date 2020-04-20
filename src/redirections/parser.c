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

static char *clear_redirect_path(char *path)
{
    int i = 0;

    for (; path[0] == ' ' || path[0] == '\t'; path++);
    for (; path[i] != ' ' && path[i] != '\0'; i++);
    path[i] = '\0';
    return path;
}

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
        /*if (size == 4)
            *fd = open(path, O_RDWR | O_APPEND, 0664);
        else*/ if (size == 3)
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

int parser(char ***env, int exit_value, char *cmd)
{
    char **parsed = my_str_to_array(cmd, "<>", true);
    int size = 0;
    int cmd_type = manage_parser_errors(parsed, &size);
    int temp_dup = parsed[1] ? dup(!my_strcmp(parsed[1], ">")) : -1;
    int fd;

    if (cmd_type != EXIT_SUCCESS) {
        free_tab(parsed);
        return cmd_type == EXIT_ERROR ? EXIT_ERROR
        : cmd_to_argv(cmd, env, exit_value);
    }
    if (temp_dup == -1 || do_redirects(parsed, &fd, size) == EXIT_ERROR) {
        free_tab(parsed);
        return EXIT_ERROR;
    }
    exit_value = cmd_to_argv(parsed[0], env, exit_value);
    if (dup2(temp_dup, !my_strcmp(parsed[1], ">")) == -1 || close(fd))
        return EXIT_ERROR;
    free_tab(parsed);
    return exit_value;
}