/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

void display_info(data_t *data)
{
    my_printf("#number_of_ants\n%i\n", data->nb_ants);
    my_printf("#rooms\n");
    print_array_str(data->every_rooms);
    my_printf("#tunnels\n");
    print_array_str(data->path);
    my_printf("#moves\n");
}
