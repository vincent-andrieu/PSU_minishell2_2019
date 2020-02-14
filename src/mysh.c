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

static char *get_cmd(void)
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

static int minishell(char ***env, int exit_value)
{
    char *cmd = get_cmd();
    char **argv = cmd != NULL ? my_str_to_array(cmd, " \t", false) : NULL;

    if (cmd == NULL) {
        my_cd(NULL, NULL);
        for (int i = 0; (*env)[i]; free((*env)[i]), i++);
        free(*env);
        if (isatty(0))
            my_putstr("exit\n");
        exit(exit_value);
    }
    free(cmd);
    if (argv == NULL)
        return exit_value;
    exit_value = interpretor(argv, env, exit_value);
    for (int i = 0; argv[i]; free(argv[i]), i++);
    free(argv);
    return exit_value;
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
        exit_value = minishell(&env, exit_value);
    }
    for (int i = 0; env[i]; free(env[i]), i++);
    free(env);
    my_cd(NULL, NULL);
    return exit_value;
}