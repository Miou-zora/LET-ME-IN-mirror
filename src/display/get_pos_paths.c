/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

int get_pos_paths(char ***all_paths, int **ants, int nbr_paths)
{
    int pos_min = 0;
    int value_min = get_len_array(all_paths[0]) + count_int_array(ants[0]);
    int value_cursor = 0;

    for (int i = 1; i < nbr_paths; i++) {
        value_cursor = get_len_array(all_paths[i]) + count_int_array(ants[i]);
        if (value_cursor < value_min) {
            value_min = value_cursor;
            pos_min = i;
        }
    }
    return (pos_min);
}
