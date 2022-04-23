/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_nbr_elements
*/

#include "lem_in.h"

int check_nbr_elements(error_comter_t *error_comter_s)
{
    if (error_comter_s->ants > 1) {
        my_putstr_error(TO_MUCH_ANTS);
        return (84);
    }
    if (error_comter_s->start > 1) {
        my_putstr_error(TO_MUCH_START);
        return (84);
    }
    if (error_comter_s->end > 1) {
        my_putstr_error(TO_MUCH_END);
        return (84);
    }
    return (0);
}

int check_error_file_end(error_comter_t *error_comter_s)
{
    if (error_comter_s->ants == 0) {
        my_putstr_error(NO_ANTS);
        return (84);
    }
    if (error_comter_s->start == 0) {
        my_putstr_error(NO_START);
        return (84);
    }
    if (error_comter_s->end == 0) {
        my_putstr_error(NO_END);
        return (84);
    }
    return (0);
}
