/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

int **get_ants(char ***all_paths, int nbr_paths, data_t *data)
{
    int **ants = NULL;
    int pos_paths = 0;

    if (all_paths == NULL) {
        return (NULL);
    }
    ants = my_calloc(nbr_paths + 1, sizeof(*ants));
    for (int i = 0; nbr_paths != i; i++) {
        ants[i] = my_calloc((data->nb_ants + 1), sizeof(*ants));
    }
    for (int i = 1; i <= data->nb_ants; i++) {
        pos_paths = get_pos_paths(all_paths, ants, nbr_paths);
        append_int_list(ants[pos_paths], i);
    }
    return (ants);
}
