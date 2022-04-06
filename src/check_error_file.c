/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

int check_error_file(error_comter_t *error_comter_s)
{
    if (error_comter_s->ants > 1 || error_comter_s->start > 1 ||
    error_comter_s->end > 1)
        return (84);
    return (0);
}

int check_error_file_end(error_comter_t *error_comter_s)
{
    if (error_comter_s->ants == 0 || error_comter_s->start == 0 ||
    error_comter_s->end == 0)
        return (84);
    return (0);
}
