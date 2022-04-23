/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** get_value
*/

#include "lem_in.h"

int get_start(char **save_data, char *buff, error_comter_t *error_comter_s,
data_t *data_s)
{
    if (get_len_array(save_data) == 3 && error_comter_s->is_next_start == 1) {
        error_comter_s->is_next_start = 0;
        error_comter_s->start += 1;
        data_s->start = my_strdup(buff);
        save_every_rooms(data_s, buff);
        return (0);
    }
    if (my_strcmp(buff, "##start") == 0) {
        error_comter_s->is_next_start = 1;
        save_every_rooms(data_s, buff);
        return (0);
    }
    return (1);
}

int get_end(char **save_data, char *buff, error_comter_t *error_comter_s,
data_t *data_s)
{
    if (get_len_array(save_data) == 3 && error_comter_s->is_next_end == 1) {
        error_comter_s->is_next_end = 0;
        error_comter_s->end += 1;
        data_s->end = my_strdup(buff);
        save_every_rooms(data_s, buff);
        return (0);
    }
    if (my_strcmp(buff, "##end") == 0) {
        error_comter_s->is_next_end = 1;
        save_every_rooms(data_s, buff);
        return (0);
    }
    return (1);
}

void get_rooms_and_tunnels(char **save_data, char *buff, data_t *data_s)
{
    if (get_len_array(save_data) == 3) {
        save_every_rooms(data_s, buff);
        save_room(data_s, buff);
    }
    if (get_len_array(save_data) == 1) {
        save_tunnel(data_s, buff);
    }
}

int free_and_return(char * tmp, char **save_data, int nb, char *message)
{
    if (nb == 84)
        my_putstr_error(message);
    if (tmp != NULL)
        free(tmp);
    free(save_data);
    return (nb);
}

int analyse_get_value(char *tmp, data_t *data_s,
error_comter_t *error_comter_s)
{
    char **save_data = NULL;
    char *line = my_strdup(tmp);

    save_data = data_to_array_str(line, " ");
    if (get_len_array(save_data) != 1 && get_len_array(save_data) != 3
    && get_len_array(save_data) != 0)
        return (free_and_return(line, save_data, 84, "to long line"));
    if (is_str_nbr(tmp) == 0) {
        if (my_getnbr(tmp) == -1)
            return (free_and_return(line, save_data, 0, NULL));
        data_s->nb_ants = my_getnbr(tmp);
        error_comter_s->ants += 1;
        return (free_and_return(line, save_data, 0, NULL));
    }
    if (get_start(save_data, tmp, error_comter_s, data_s) == 0 ||
    get_end(save_data, tmp, error_comter_s, data_s) == 0)
        return (free_and_return(line, save_data, 0, NULL));
    get_rooms_and_tunnels(save_data, tmp, data_s);
    return (free_and_return(line, save_data, 0, NULL));
}