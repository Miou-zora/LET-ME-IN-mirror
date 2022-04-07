/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** error_in_data
*/

#include "lem_in.h"

int check_end_start(char *data)
{
    char *save = my_strdup(data);
    char **tmp = data_to_array_str(data, " ");

    if (get_len_array(tmp) != 3)
        return (84);
    for (int i = 0; tmp[0][i] != '\0'; i++) {
        if (tmp[0][i] == '-')
            return (84);
    }
    for (int i = 1; tmp[i] != NULL; i++)
        if (is_str_nbr(tmp[i]) == 84)
            return (84);
    free(tmp);
    free(save);
    return (0);
}

int error_data(data_t *data_s)
{
    if (data_s->nb_ants < 1)
        return (84);
    if (check_end_start(data_s->start) == 84 ||
    check_end_start(data_s->end) == 84)
        return (84);
    for (int i = 0; data_s->room_name[i] != NULL; i++) {
        if (check_end_start(data_s->room_name[i]) == 84)
            return (84);
    }
    return (0);
}
