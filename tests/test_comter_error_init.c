/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** test_comter_error_init
*/

#include "lem_in.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void init_error_comter(error_comter_t *error_comter_s);

int test_init(error_comter_t *error_comter_s)
{
    init_error_comter(error_comter_s);
    if (error_comter_s->is_next_start != 0 || error_comter_s->is_next_end != 0 || error_comter_s->ants != 0 || error_comter_s->start != 0 || error_comter_s->end != 0)
        return (84);
    return (0);
}

Test(test_init, test_if_init_is_good)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    cr_assert_eq(test_init(error_comter_s), 0);
    free(error_comter_s);
}