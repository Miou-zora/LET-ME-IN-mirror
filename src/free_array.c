/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** free_array
*/

#include <stdlib.h>

void free_array(char **arr)
{
    if (arr != NULL) {
        for (int j = 0; arr[j] != NULL; j++)
            free(arr[j]);
    }
    free(arr);
}
