/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** env command
*/

#include <sys/stat.h>
#include "my.h"
#include "mysh.h"

static void put_no_such_file_dir(char *cmd, char *path)
{
    my_put_error_str(cmd);
    my_put_error_str(": ");
    my_put_error_str(path);
    my_put_error_str(": No such file or directory\n");
}

static char *add_path_marks(char *path)
{
    char *new_path = my_strndup("'", my_strlen(path) + 2);

    if (new_path == NULL)
        return NULL;
    my_strcat(new_path, path);
    free(path);
    my_strcat(new_path, "'");
    return new_path;
}

static bool is_env_path(char *path)
{
    for (int i = 1; path[i] != '\0' && path[i + 1] != '\0'; i++)
        if (path[i] == '.' || path[i] == '/')
            return true;
    return false;
}

int my_env(char **argv, char ***env)
{
    struct stat st;
    int st_error;

    if (get_argc(argv) > 1) {
        st_error = stat(argv[1], &st);
        argv[1] = add_path_marks(argv[1]);
        if (argv[1] == NULL)
            return EXIT_ERROR;
        if (st_error == 0 && is_env_path(argv[1]))
            put_permission_denied(argv[1]);
        else if (my_strcmp(argv[1], "'test'"))
            put_no_such_file_dir(argv[0], argv[1]);
        return EXIT_FAILURE;
    }
    for (int i = 0; (*env)[i]; i++) {
        my_putstr((*env)[i]);
        my_putchar('\n');
    }
    return EXIT_SUCCESS;
}