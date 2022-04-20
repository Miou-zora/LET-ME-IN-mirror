/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** test_analyse_get_value
*/

#include "lem_in.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

Test(analyse_get_value, find_ants)
{
    char *buff = my_strdup("38\n");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    cr_assert_eq(analyse_get_value(buff, data_s, error_comter_s), 0);
    free(buff);
    free(data_s);
    free(error_comter_s);
}

Test(analyse_get_value, no_buff)
{
    char *buff = my_strdup("\0");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    cr_assert_eq(analyse_get_value(buff, data_s, error_comter_s), 0);
    free(buff);
    free(data_s);
    free(error_comter_s);
}

Test(analyse_get_value, buff_with_comments)
{
    char *buff = my_strdup("38#arbre\n");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    cr_assert_eq(analyse_get_value(buff, data_s, error_comter_s), 0);
    free(buff);
    free(data_s);
    free(error_comter_s);
}

Test(analyse_get_value, get_start_or_end)
{
    char *buff = my_strdup("##start\n");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    error_comter_s->count_part = 1;
    cr_assert_eq(analyse_get_value(buff, data_s, error_comter_s), 0);
    free(buff);
    free(data_s);
    free(error_comter_s);
}
