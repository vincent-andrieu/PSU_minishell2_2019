/*
** EPITECH PROJECT, 2019
** minishell 1
** File description:
** check wich command is enter
*/

#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include "my.h"
#include "mysh.h"

cmd_ls_t const cmd_list[] = {
    {"cd", my_cd},
    {"exit", my_exit},
    {"env", my_env},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {NULL, NULL}
};

char const *errors_msg_list[] =
{
    "Hangup",
    "",
    "Quit",
    "Illegal instruction",
    "Trace/BPT trap",
    "Abort",
    "BUS error",
    "Floating exception",
    "Killed",
    "User signal 1",
    "Segmentation fault",
    "User signal 2",
    "Broken pipe",
    "Alarm clock",
    "Terminated",
    "Stack limit exceeded",
    "Child process has stopped or exited, changed",
    "Continue executing, if stopped",
    "Suspended (signal)",
    "Suspended",
    "Background read from tty",
    "Background write to tty",
    "",
    "Cputime limit exceeded",
    "Filesize limit exceeded",
    "Virtual time alarm",
    "Profiling time clock",
    "",
    "Pollable event occured",
    "Pollable event occured",
    "Power failure",
    "Bad system call",
    NULL
};

static void exe_cmd(char **argv, char **env)
{
    struct stat st;
    int value = stat(argv[0], &st);

    if ((value == 0 && access(argv[0], X_OK) == -1)
    || (value == 0 && S_ISDIR(st.st_mode))) {
        my_put_error_str(argv[0]);
        my_put_error_str(": Permission denied.\n");
        exit(EXIT_FAILURE);
    }
    if (!access(argv[0], X_OK) && execve(argv[0], argv, env) == -1) {
        my_put_error_str(argv[0]);
        my_put_error_str(": Exec format error. Wrong Architecture.\n");
        exit(EXIT_FAILURE);
    }
}

static char **get_paths(char **env)
{
    int i = 0;

    for (; env[i] && my_strncmp(env[i], "PATH=", 5); i++);
    if (env[i] == NULL)
        return NULL;
    return my_str_to_array(env[i] + 5, ":", false);
}

static int search_cmd(char **paths, char **argv, char **env)
{
    char *prog;

    for (int i = 0; paths[i]; i++) {
        prog = my_strndup(paths[i],
            my_strlen(paths[i]) + 1 + my_strlen(argv[0]));
        if (prog == NULL)
            return EXIT_ERROR;
        my_strcat(prog, "/");
        my_strcat(prog, argv[0]);
        if (!access(prog, R_OK))
            execve(prog, argv, env);
        free(prog);
    }
    return EXIT_FAILURE;
}

static int other_cmd(char **argv, char **env)
{
    char **paths = get_paths(env);
    int exit_value;

    if (!is_term_exist(env)) {
        my_put_error_str("TERM environment variable not set.\n");
        exit(EXIT_FAILURE);
    }
    if (paths != NULL) {
        exit_value = search_cmd(paths, argv, env);
        for (int i = 0; paths[i]; free(paths[i]), i++);
        free(paths);
        if (exit_value != EXIT_FAILURE)
            exit(exit_value);
    }
    exe_cmd(argv, env);
    put_command_not_found(argv[0]);
    exit(EXIT_FAILURE);
}

int interpretor(char **argv, char ***env, int exit_value)
{
    int pid_child = -1;
    int argc = get_argc(argv);

    if (argc <= 0)
        return exit_value;
    for (int i = 0; cmd_list[i].cmd != NULL; i++)
        if (!my_strcmp(argv[0], cmd_list[i].cmd))
            return cmd_list[i].func(argv, env);
    pid_child = fork();
    if (pid_child == 0)
        return other_cmd(argv, *env);
    waitpid(pid_child, &exit_value, 0);
    if (WTERMSIG(exit_value) != 0) {
        my_put_error_str(errors_msg_list[WTERMSIG(exit_value) - 1]);
        if (WIFSIGNALED(exit_value) && WCOREDUMP(exit_value))
            my_put_error_str(" (core dumped)");
        my_put_error_str("\n");
    }
    return WEXITSTATUS(exit_value);
}