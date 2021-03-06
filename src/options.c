/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** options
*/

#include "my.h"
#include "my_ls.h"
#include <stdlib.h>
#include <stdbool.h>

static void read_options_from_arg(char *str, char **options)
{
    int i = 0;
    char tmp[2] = "-\0";

    while (str[i]) {
        if (IS_ALPHA(str[i]) && !char_in_str(str[i], *options)) {
            tmp[0] = str[i];
            str_append(options, tmp);
        }
        i++;
    }
}

bool char_in_str(char c, char *str)
{
    if (!str)
        return (false);
    while (*str) {
        if (*str == c)
            return (true);
        str++;
    }
    return (false);
}

static bool check_options(char *options)
{
    if (options == NULL)
        return (true);
    while (*options) {
        if (!char_in_str(*options, ALLOWED_OPTIONS))
            return (false);
        options++;
    }
    return (true);
}

char *get_options(int ac, char **av)
{
    char *ret = NULL;

    if (ac == 1)
        return (NULL);
    for (int i = 1; i < ac; i++) {
        if (!my_strcmp(av[i], "--"))
            return (ret);
        if (av[i][0] == '-')
            read_options_from_arg(av[i], &ret);
    }
    if (!check_options(ret)) {
        my_puterr("Invalid option\n");
        exit(84);
    }
    return (ret);
}