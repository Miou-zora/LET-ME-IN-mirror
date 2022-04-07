/*
** EPITECH PROJECT, 2022
** B-PSU-200-NAN-2-1-mysokoban-alexandre.franquet [WSL: Ubuntu]
** File description:
** get_len_array
*/

#include "../include/my.h"
#include <stddef.h>

int get_len_array(char **array)
{
    int i = 0;

    if (array == NULL)
        return (0);
    while (array[i] != NULL) {
        i++;
    }
    return (i);
}
