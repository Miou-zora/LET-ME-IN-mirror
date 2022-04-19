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
    if (get_len_array(save_data) == 3 && error_comter_s->is_next_start == 1 &&
    error_comter_s->count_part == 1) {
        error_comter_s->is_next_start = 0;
        error_comter_s->start += 1;
        data_s->start = my_strdup(buff);
        save_every_rooms(data_s, buff);
        return (0);
    }
    if (my_strcmp(buff, "##start\n") == 0 && error_comter_s->count_part == 1) {
        error_comter_s->is_next_start = 1;
        save_every_rooms(data_s, buff);
        return (0);
    }
    return (1);
}

int get_end(char **save_data, char *buff, error_comter_t *error_comter_s,
data_t *data_s)
{
    if (get_len_array(save_data) == 3 && error_comter_s->is_next_end == 1 &&
    error_comter_s->count_part == 1) {
        error_comter_s->is_next_end = 0;
        error_comter_s->end += 1;
        data_s->end = my_strdup(buff);
        save_every_rooms(data_s, buff);
        return (0);
    }
    if (my_strcmp(buff, "##end\n") == 0 && error_comter_s->count_part == 1) {
        error_comter_s->is_next_end = 1;
        save_every_rooms(data_s, buff);
        return (0);
    }
    return (1);
}

void get_rooms_and_tunnels(char **save_data, char *buff, data_t *data_s, error_comter_t
*error_comter_s)
{
    if (get_len_array(save_data) == 3 && error_comter_s->count_part == 1) {
        save_every_rooms(data_s, buff);
        save_room(data_s, buff);
    }
    if (get_len_array(save_data) == 1) {
        error_comter_s->count_part = 2;
        save_tunnel(data_s, buff);
    }
}

int free_and_return(char *tmp, char **save_data, int nb, char *message)
{
    if (nb == 84)
        my_putstr_error(message);
    free(tmp);
    free(save_data);
    return (nb);
}

int analyse_get_value(char *buff, data_t *data_s,
error_comter_t *error_comter_s)
{
    char **save_data = NULL;
    char *tmp = NULL;

    buff = remove_space(remove_comments(buff));
    tmp = my_strdup(buff);
    if (buff[0] == '\0')
        return (free_and_return(tmp, save_data, 0, NULL));
    save_data = data_to_array_str(tmp, " ");
    if (get_len_array(save_data) != 1 && get_len_array(save_data) != 3
    && get_len_array(save_data) != 0)
        return (free_and_return(tmp, save_data, 84, TO_MUCH_ANTS));
    if (is_str_nbr(buff) == 0) {
        error_comter_s->ants += 1;
        data_s->nb_ants = my_getnbr(buff);
        error_comter_s->count_part = 1;
        return (free_and_return(tmp, save_data, 0, NULL));
    }
    if (error_comter_s->count_part == 0)
        return (free_and_return(tmp, save_data, 84, NO_ANTS));
    if (get_start(save_data, buff, error_comter_s, data_s) == 0 ||
    get_end(save_data, buff, error_comter_s, data_s) == 0)
        return (free_and_return(tmp, save_data, 0, NULL));
    get_rooms_and_tunnels(save_data, buff, data_s, error_comter_s);
    return (free_and_return(tmp, save_data, 0, NULL));
}
