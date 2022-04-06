/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** test_is_numbuer
*/

#include "lem_in.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

Test(is_nbr, no_number_in_str)
{
    char *str = "hola";

    cr_assert_eq(is_str_nbr(str), 84);
}

Test(is_nbr, only_nbrs)
{
    char *str = "135213";

    cr_assert_eq(is_str_nbr(str), 0);
}

Test(is_nbr, nbrs_and_char)
{
    char *str = "h31ola13";

    cr_assert_eq(is_str_nbr(str), 84);
}

Test(is_nbr, start_number_and_char)
{
    char *str = "4645h31ola13";

    cr_assert_eq(is_str_nbr(str), 84);
}
