/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

void display_path(data_t *data, list_t **tab_node)
{
    char ***moves = get_all_path(tab_node[0], data->end);
    for (int i = 0; moves[i] != NULL; i++) {
        for (int j = 0; moves[i][j] != NULL; j++)
            my_printf("%s", moves[i][j]);
    }
}
