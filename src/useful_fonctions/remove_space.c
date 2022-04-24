/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** remove_space
*/

#include "lem_in.h"

char *remove_space(char *buff)
{
    for (int i = my_strlen(buff); buff[i] == ' ' || buff[i] == '\n'; i--) {
        buff[i] = '\0';
    }
    buff[my_strlen(buff)] = '\n';
    return (buff);
}
