/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

void display_path(data_t *data, list_t **tab_node)
{
    char ***all_paths = get_all_path(tab_node[0], data->end, tab_node);
    int nbr_paths = get_len_paths(all_paths);
    int **ants = get_ants(all_paths, nbr_paths, data);
    int len_first = get_len_array(all_paths[0]) + count_int_array(ants[0]);

    for (int i = 1; len_first >= i; i++) {
        display_movement(ants, all_paths, i);
        if (i != len_first) {
            my_putchar('\n');
        }
    }
    for (int i = 0; all_paths[i] != NULL; i++) {
        free(all_paths[i]);
        free(ants[i]);
    }
    free(all_paths);
    free(ants);
}
