/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** test_get_value
*/

#include "lem_in.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

Test(get_start, find_start)
{
    char *buff = my_strdup("##start");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    char **save_data = data_to_array_str(buff, " ");
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    error_comter_s->count_part = 1;
    cr_assert_eq(get_start(save_data, buff, error_comter_s, data_s), 0);
    free(buff);
    free(data_s);
    free(error_comter_s);
    free(save_data);
}

Test(get_start, find_start_pos)
{
    char *buff = my_strdup("12 8 3\n");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    char **save_data = data_to_array_str(buff, " ");
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    error_comter_s->count_part = 1;
    error_comter_s->is_next_start = 1;
    cr_assert_eq(get_start(save_data, buff, error_comter_s, data_s), 0);
    free(buff);
    free(data_s);
    free(error_comter_s);
    free(save_data);
}

Test(get_start, bad_room)
{
    char *buff = my_strdup("12 8\n");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    char **save_data = data_to_array_str(buff, " ");
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    error_comter_s->is_next_start = 1;
    cr_assert_eq(get_start(save_data, buff, error_comter_s, data_s), 1);
    free(buff);
    free(data_s);
    free(error_comter_s);
    free(save_data);
}

Test(get_start, no_start_find)
{
    char *buff = my_strdup("12 8 8\n");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    char **save_data = data_to_array_str(buff, " ");
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    error_comter_s->is_next_start = 0;
    cr_assert_eq(get_start(save_data, buff, error_comter_s, data_s), 1);
    free(buff);
    free(data_s);
    free(error_comter_s);
    free(save_data);
}

Test(get_start, nothing_find)
{
    char *buff = my_strdup("12\n");
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    char **save_data = data_to_array_str(buff, " ");
    data_t *data_s = malloc(sizeof(data_t));

    if (!error_comter_s || !data_s)
        return;
    error_comter_s->is_next_start = 0;
    cr_assert_eq(get_start(save_data, buff, error_comter_s, data_s), 1);
    free(buff);
    free(data_s);
    free(error_comter_s);
    free(save_data);
}
