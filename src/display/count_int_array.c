/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

int count_int_array(int *ants)
{
    int i = 0;
    while (ants[i] != 0) {
        i++;
    }
    return (i);
}
