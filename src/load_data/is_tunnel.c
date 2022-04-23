/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** is_tuunel
*/

#include "lem_in.h"

int is_tunnel(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '-')
            return (0);
    return (1);
}
