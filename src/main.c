/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** mysh main
*/

#include "mysh.h"

int main(int argc, char **argv, char **env)
{
    argc++;
    argv++;
    return mysh(env);
}