/*
** EPITECH PROJECT, 2022
** B-PSU-101-NAN-1-1-minishell1-quentin.brejoin
** File description:
** my_arraydup
*/

#include <unistd.h>
#include <stdlib.h>

int get_len_array(char **array);

char **my_arraycpy(char **dest , char **src);

void *my_calloc(int elem_count, int elem_size);

char **my_arraydup(char **src)
{
    char **dest = my_calloc((get_len_array(src) + 1), sizeof(char *));

    dest = my_arraycpy(dest, src);
    return (dest);
}
