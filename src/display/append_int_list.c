/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

void append_int_list(int *list, int value)
{
    int i = 0;

    for (; list[i] != 0; i++);
    list[i] = value;
}
