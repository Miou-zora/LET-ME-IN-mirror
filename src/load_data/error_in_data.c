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
    data[my_strlen(tmp[0])] = '\0';
    return (free_and_return(save, tmp, 0, NULL));
}

int compare_name(char **tmp, int i)
{
    for (int j = i + 1; tmp[j] != NULL; j++) {
        if (my_strcmp(tmp[i], tmp[j]) == 0) {
            my_putstr_error(SAME_NAME);
            return (84);
        }
    }
    return (0);
}

int check_name(data_t *data_s)
{
    char **tmp = my_calloc(sizeof(char *),
    (get_len_array(data_s->room_name) + 3));

    tmp[0] = my_strdup(data_s->start);
    for (int i = 1; i != get_len_array(data_s->room_name) + 1; i++) {
        tmp[i] = my_strdup(data_s->room_name[i - 1]);
    }
    tmp[get_len_array(data_s->room_name) + 1] = my_strdup(data_s->end);
    for (int i = 0; tmp[i] != NULL; i++) {
        if (compare_name(tmp, i) == 84)
            return (84);
    }
    free_array(tmp);
    return (0);
}

int check_name_room(data_t *data_s)
{
    if (data_s->room_name == NULL)
        return (0);
    for (int i = 0; data_s->path[i] != NULL; i++) {
        if (check_path_name(data_s, data_s->path[i]) == 84)
            return (84);
    }
    return (0);
}

int error_data(data_t *data_s)
{
    if (data_s->path == NULL)
        return (84);
    if (data_s->nb_ants < 1) {
        my_putstr_error(NEGATIVE_ANTS);
        return (84);
    }
    if (check_end_start(data_s->start) == 84 ||
    check_end_start(data_s->end) == 84)
        return (84);

    for (int i = 0; data_s->room_name[i] != NULL; i++) {
        if (check_end_start(data_s->room_name[i]) == 84)
            return (84);
    }
    if (check_name(data_s) == 84)
        return (84);
    if (check_name_room(data_s) == 84)
        return (84);
    return (0);
}
