/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** my_putstr_error
*/

#include <unistd.h>
#include "lem_in.h"

void my_putstr_error(char *error)
{
    write(2, error, my_strlen(error));
}
