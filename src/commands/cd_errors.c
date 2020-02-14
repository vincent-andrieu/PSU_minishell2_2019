/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** cd errors
*/

#include <sys/stat.h>
#include "my.h"
#include "mysh.h"

static void put_error_not_dir(char **argv)
{
    my_put_error_str(argv[1]);
    my_put_error_str(": Not a directory.\n");
}

static void put_no_home(char **argv)
{
    if (get_argc(argv) == 1) {
        my_put_error_str(argv[0]);
        my_put_error_str(": No home directory.\n");
    } else
        my_put_error_str("No $home variable set.\n");
}

int check_cd_errors(char **argv, char *path)
{
    struct stat st;

    if (argv == NULL)
        return EXIT_FAILURE;
    if (path == NULL) {
        put_no_home(argv);
        return EXIT_FAILURE;
    } else if (get_argc(argv) > 2) {
        put_too_many_args(argv[0]);
        return EXIT_FAILURE;
    }
    if (stat(path, &st) == -1) {
        my_put_error_str(path);
        my_put_error_str(": No such file or directory.\n");
        return EXIT_FAILURE;
    } else if (!S_ISDIR(st.st_mode)) {
        put_error_not_dir(argv);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}