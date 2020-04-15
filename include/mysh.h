/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** header
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef MYSH_H_
#define MYSH_H_

#define EXIT_ERROR 84

typedef struct cmd_ls_s
{
    char const *cmd;
    int (*func)(char **argv, char ***env);
} cmd_ls_t;

typedef struct cd_flags_s
{
    char const symbol;
    char const *var;
} cd_flags_t;

int mysh(char **env);
int interpretor(char **argv, char ***env, int exit_value);
int choose_cmd_type(char **argv, char ***env, int exit_value);
bool is_term_exist(char **env);
int get_argc(char **argv);
char **env_dup(char **env, int more);
int my_cd(char **argv, char ***env);
int my_exit(char **argv, char ***env);
int my_env(char **argv, char ***env);
int my_setenv(char **argv, char ***env);
int my_unsetenv(char **argv, char ***env);
char *add_name_equal(char *name);
int edit_env(char **var, char *name);

#endif

#ifndef ERRORS_H_
#define ERRORS_H_

int check_cd_errors(char **argv, char *path);
void put_permission_denied(char *path);
void put_too_many_args(char *cmd);
void put_error_unalphanum(char *cmd, char *str);
void put_command_not_found(char *cmd);

#endif