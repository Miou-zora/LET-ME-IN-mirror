/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** remove_space
*/

#include "lem_in.h"

char *remove_space(char *buff)
{
    int i = 0;

    buff = my_revstr(buff);
    for (i = 0; buff[i] == ' ' || buff[i] == '\n'; i++);
    buff = &buff[i];
    buff = my_revstr(buff);
    buff[my_strlen(buff) + 1] = '\n';
    buff[my_strlen(buff) + 2] = '\0';
    return (buff);
}
