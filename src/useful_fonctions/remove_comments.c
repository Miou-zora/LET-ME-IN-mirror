/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** remove_comments
*/

#include <unistd.h>
#include "my.h"

char *remove_comments(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (i >= 1 && buff[i - 1] == '#' && buff[i] == '#') {
            continue;
        }
        if (buff[i] == '#' && buff[i + 1] != '#') {
            buff[i] = '\n';
            buff[i + 1] = '\0';
            break;
        }
        if (buff[i] == '#' && buff[i + 1] == '#' && my_strncmp(buff, "##end", 8)
        != 0 && my_strncmp(buff, "##start", 8) != 0) {
            buff[i] = '\n';
            buff[i + 1] = '\0';
            break;
        }
    }
    return (buff);
}
