/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** is_room
*/

#include "lem_in.h"

int is_room(char *data)
{
    char *save = my_strdup(data);
    char **tmp = data_to_array_str(save, " ");

    if (get_len_array(tmp) != 3)
        return (free_and_return(save, tmp, 84, NO_NUMBER));
    for (int i = 0; tmp[0][i] != '\0'; i++) {
        if (tmp[0][i] == '-') {
            return (free_and_return(save, tmp, 84, DASH_IN_NAME));
        }
    }
    for (int i = 1; tmp[i] != NULL; i++)
        if (is_str_nbr(tmp[i]) == 84) {
            return (free_and_return(save, tmp, 84, NO_NUMBER));
        }
    return (free_and_return(save, tmp, 0, NULL));
}
