/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** test_check_error_file
*/

#include "lem_in.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

Test(check_error_file, many_ants_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->ants = 2;
    cr_assert_eq(check_error_file(error_comter_s), 84);
    free(error_comter_s);
}

Test(check_error_file, no_ants_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->ants = 0;
    error_comter_s->start = 1;
    error_comter_s->end = 1;
    cr_assert_eq(check_error_file_end(error_comter_s), 84);
    free(error_comter_s);
}

Test(check_error_file, one_ants_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->ants = 1;
    error_comter_s->start = 1;
    error_comter_s->end = 1;
    cr_assert_eq(check_error_file_end(error_comter_s), 0);
    free(error_comter_s);
}

Test(check_error_file, zero_ants_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->ants = 0;
    error_comter_s->start = 1;
    error_comter_s->end = 1;
    cr_assert_eq(check_error_file_end(error_comter_s), 84);
    free(error_comter_s);
}

Test(check_error_file, no_start_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->start = 0;
    error_comter_s->ants = 1;
    error_comter_s->end = 1;
    cr_assert_eq(check_error_file_end(error_comter_s), 84);
    free(error_comter_s);
}

Test(check_error_file, good_start_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->start = 1;
    error_comter_s->ants = 1;
    error_comter_s->end = 1;
    cr_assert_eq(check_error_file(error_comter_s), 0);
    free(error_comter_s);
}

Test(check_error_file, many_start_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->start = 2;
    cr_assert_eq(check_error_file(error_comter_s), 84);
    free(error_comter_s);
}

Test(check_error_file, no_end_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->end = 0;
    error_comter_s->start = 1;
    error_comter_s->ants = 1;
    cr_assert_eq(check_error_file_end(error_comter_s), 84);
    free(error_comter_s);
}

Test(check_error_file, good_end_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->start = 1;
    error_comter_s->ants = 1;
    error_comter_s->end = 1;
    cr_assert_eq(check_error_file(error_comter_s), 0);
    free(error_comter_s);
}

Test(check_error_file, many_end_declaration)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));

    error_comter_s->end = 2;
    cr_assert_eq(check_error_file(error_comter_s), 84);
    free(error_comter_s);
}
