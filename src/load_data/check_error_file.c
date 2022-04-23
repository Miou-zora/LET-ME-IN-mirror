/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

void init_error_comter(error_comter_t *error_comter_s)
{
    error_comter_s->is_next_start = 0;
    error_comter_s->is_next_end = 0;
    error_comter_s->ants = 0;
    error_comter_s->start = 0;
    error_comter_s->end = 0;
    error_comter_s->count_part = 0;
}

int check_error_file(data_t *data, char **file)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    int is_error = 0;

    if (!error_comter_s)
        return (84);
    init_error_comter(error_comter_s);
    for (int i = 0; file[i] != NULL; i++) {
        is_error = analyse_get_value(file[i], data, error_comter_s);
        if (is_error == 84 || check_nbr_elements(error_comter_s) == 84) {
            data->is_error = 1;
        }
    }
    if (data->is_error == 1)
        return (84);
    return (0);
}
