/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** lem_in
*/

#include "lem_in.h"

int lem_in(int ac, char **av)
{
    data_t *data_s = malloc(sizeof(data_t));

    (void)av;
    if (ac != 1)
        return (84);
    load_data_from_file(data_s);
    free(data_s);
    return (0);
}
