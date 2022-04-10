/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** test_free_array
*/

#include "lem_in.h"
#include <criterion/criterion.h>

Test(free_array, test_if_value_is_free)
{
    char *buff_one = my_strdup("1\n");
    char *buff_two = my_strdup("2\n");
    char *buff_three = NULL;
    char **data = my_calloc(3, sizeof(*data));

    data[0] = buff_one;
    data[1] = buff_two;
    data[2] = buff_three;
    free_array(data);
}

Test(free_array, test_if_null_is_not_free)
{
    char **data = NULL;

    free_array(data);
}
