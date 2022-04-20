/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

void display_info(data_t *data, list_t **tab_node)
{
    my_printf("#number_of_ants\n%i\n", data->nb_ants);
    my_printf("#rooms\n");
    print_array_str(data->every_rooms);
    my_printf("#tunnels\n");
    for (int i = 0; data->path[i] != NULL; i++) {
        my_printf("%s", data->path[i]);
    }
    my_printf("#moves");
    display_path(data, tab_node);
}