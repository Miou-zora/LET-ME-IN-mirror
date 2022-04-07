/*
** EPITECH PROJECT, 2022
** B-PSU-101-NAN-1-1-minishell1-quentin.brejoin
** File description:
** my_arraycpy
*/

#include <unistd.h>

char *my_strdup(char const *src);

void print_array_str(char **arr);

void my_putstr(char *str);

char **my_arraycpy(char **dest , char **src)
{
    int i = 0;

    for (; src[i] != NULL; i++) {
        dest[i] = my_strdup(src[i]);
    }
    dest[i] = NULL;
    return (dest);
}
