/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** get_value
*/

#include "lem_in.h"

void get_tunnel(char **save_data, char *buff, data_t *data_s,
error_comter_t *error_comter_s)
{
    if (get_len_array(save_data) == 1) {
        if (data_s->every_rooms == NULL) {
            data_s->is_error = 1;
            return;
        }
        if (error_comter_s->actual_part != 2) {
            my_printf("#tunnels\n");
            error_comter_s->count_parts += 1;
        }
        error_comter_s->actual_part = 2;
        if (is_tunnel(buff) == 1) {
            data_s->is_error = 1;
            return;
        }
        my_printf("%s\n", buff);
        save_tunnel(data_s, buff);
    }
}

void get_rooms_and_tunnels(char **save_data, char *buff, data_t *data_s,
error_comter_t *error_comter_s)
{
    if (get_len_array(save_data) == 3) {
        if (error_comter_s->actual_part != 1) {
            error_comter_s->count_parts += 1;
            my_printf("#rooms\n");
        }
        error_comter_s->actual_part = 1;
        if (is_room(buff) == 84) {
            data_s->is_error = 1;
            return;
        }
        my_printf("%s\n", buff);
        save_every_rooms(data_s, buff);
        save_room(data_s, buff);
    }
    get_tunnel(save_data, buff, data_s, error_comter_s);
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
        return (free_and_return(line, save_data, 84, "to long line\n"));
    if (is_str_nbr(tmp) == 0) {
        if (my_getnbr(tmp) == -1)
            return (free_and_return(line, save_data, 0, NULL));
        data_s->nb_ants = my_getnbr(tmp);
        error_comter_s->actual_part -= 1;
        error_comter_s->count_parts += 1;
        error_comter_s->ants += 1;
        my_printf("#number_of_ants\n%i\n", data_s->nb_ants);
        return (free_and_return(line, save_data, 0, NULL));
    }
    if (get_start(save_data, tmp, error_comter_s, data_s) == 0 ||
    get_end(save_data, tmp, error_comter_s, data_s) == 0)
        return (free_and_return(line, save_data, 0, NULL));
    get_rooms_and_tunnels(save_data, tmp, data_s, error_comter_s);
    return (free_and_return(line, save_data, 0, NULL));
}