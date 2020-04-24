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
int cmd_to_argv(char *cmd, char ***env, int exit_value);
int split_semicolons(char ***env, int exit_value, char *cmd);
char *get_cmd(void);
void free_tab(char **tab);
int redirections_parser(char ***env, int exit_value, char *cmd);
int do_double_left_redirect(char ***env, int exit_value, char **parsed);
char *clear_redirect_path(char *path);

#endif

#ifndef ERRORS_H_
#define ERRORS_H_

//mysh1
int check_cd_errors(char **argv, char *path);
void put_permission_denied(char *path);
void put_too_many_args(char *cmd);
void put_error_unalphanum(char *cmd, char *str);
int put_command_not_found(char *cmd);

//mysh2
int manage_parser_errors(char **parsed, int *size);
int ambiguous_error(void);
int is_dir_error(char *path);
int missing_redirect_error(void);
int null_command_error(void);

#endif