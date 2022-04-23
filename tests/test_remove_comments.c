/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** test_remove_comments
*/

#include "lem_in.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

Test(remove_comments, double_hashtag)
{
    char *str = my_strdup("hola ##arbre");

    cr_assert_str_eq(remove_comments(str), "hola \n");
}

Test(remove_comments, one_hashtag_with_space)
{
    char *str = my_strdup("hola #arbre");

    cr_assert_str_eq(remove_comments(str), "hola \n");
}

Test(remove_comments, one_hashtag_no_space)
{
    char *str = my_strdup("hola#arbre");

    cr_assert_str_eq(remove_comments(str), "hola\n");
}

Test(remove_comments, first_hashtag)
{
    char *str = my_strdup("#arbre");

    cr_assert_str_eq(remove_comments(str), "\n");
}

Test(remove_comments, two_comments)
{
    char *str = my_strdup("#arbre#arbre");

    cr_assert_str_eq(remove_comments(str), "\n");
}

Test(remove_comments, two_hashtag)
{
    char *str = my_strdup("##arbre");

    cr_assert_str_eq(remove_comments(str), "\n");
}
