/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

int get_len_paths(char ***all_paths)
{
    int i = 0;

    while (all_paths[i] != NULL) {
        i++;
    }
    return (i);
}
