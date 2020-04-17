/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** minishell 1
*/

#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"
#include "mysh.h"

static void put_prefix_command(void)
{
    char *path;

    if (isatty(0)) {
        my_putstr("\e[01;95m[");
        path = getcwd(NULL, 0);
        my_putstr(path);
        free(path);
        my_putstr("]\e[0m$> ");
    }
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

char *get_cmd(void)
{
    char *cmd = NULL;
    size_t size = 0;
    int read_size = getline(&cmd, &size, stdin);

    if (cmd == NULL || read_size <= 0) {
        free(cmd);
        return NULL;
    }
    cmd[read_size - 1] = '\0';
    return cmd;
}

static void handle_sigint(__attribute((unused))int sig)
{
    my_putchar('\n');
    put_prefix_command();
}

int mysh(char **env)
{
    int exit_value = EXIT_SUCCESS;

    env = env_dup(env, 0);
    if (env == NULL)
        return EXIT_ERROR;
    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);
    while (exit_value != EXIT_ERROR) {
        put_prefix_command();
        exit_value = split_semicolons(&env, exit_value);
    }
    for (int i = 0; env[i]; free(env[i]), i++);
    free(env);
    my_cd(NULL, NULL);
    return exit_value;
}