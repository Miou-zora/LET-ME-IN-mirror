/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** lem_in
*/

#include "lem_in.h"

void init_data(data_t *data_s)
{
    data_s->end = NULL;
    data_s->start = NULL;
    data_s->room_name = NULL;
    data_s->path = NULL;
    data_s->nb_ants = 0;
}

void free_data(data_t *data_s)
{
    free(data_s->end);
    free(data_s->start);
    free_array(data_s->path);
    free_array(data_s->room_name);
    free(data_s);
}

int lem_in(int ac, char **av)
{
    data_t *data_s = malloc(sizeof(data_t));

    (void)av;
    if (ac != 1)
        return (84);
    init_data(data_s);
    if (load_data_from_file(data_s) == 84)
        return (84);
    free_data(data_s);
    return (0);
}
