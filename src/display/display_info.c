/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

void display_info(data_t *data)
{
    my_printf("#number_of_ants\n");
    if (data->nb_ants != 0)
        my_printf("%i\n", data->nb_ants);
    my_printf("#rooms\n");
    if (data->every_rooms != NULL)
        print_array_str(data->every_rooms);
    my_printf("#tunnels\n");
    if (data->path != NULL)
        print_array_str(data->path);
    my_printf("#moves\n");
}
