/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** find_start_and_end
*/

#include "lem_in.h"

int find_end(char *buff, error_comter_t *error_comter_s, data_t *data_s)
{
    if (my_strcmp(buff, "##end") == 0) {
        if (error_comter_s->actual_part != 1) {
            my_printf("#rooms\n");
        }
        error_comter_s->actual_part = 1;
        if (error_comter_s->is_next_start == 1)
            data_s->is_error = 1;
        my_printf("%s\n", buff);
        error_comter_s->is_next_end = 1;
        save_every_rooms(data_s, buff);
        return (0);
    }
    return (1);
}

int find_start(char *buff, error_comter_t *error_comter_s, data_t *data_s)
{
    if (my_strcmp(buff, "##start") == 0) {
        if (error_comter_s->actual_part != 1) {
            my_printf("#rooms\n");
        }
        error_comter_s->actual_part = 1;
        if (error_comter_s->is_next_end == 1)
            data_s->is_error = 1;
        my_printf("%s\n", buff);
        error_comter_s->is_next_start = 1;
        save_every_rooms(data_s, buff);
        return (0);
    }
    return (1);
}

int get_start(char **save_data, char *buff, error_comter_t *error_comter_s,
data_t *data_s)
{
    if (get_len_array(save_data) == 3 && error_comter_s->is_next_start == 1) {
        if (error_comter_s->actual_part != 1) {
            my_printf("#rooms\n");
        }
        error_comter_s->actual_part = 1;
        error_comter_s->is_next_start = 0;
        error_comter_s->start += 1;
        if (is_room(buff) == 84) {
            data_s->is_error = 1;
            return (0);
        }
        my_printf("%s\n", buff);
        data_s->start = my_strdup(buff);
        save_every_rooms(data_s, buff);
        return (0);
    }
    if (find_start(buff, error_comter_s, data_s) == 0)
        return (0);
    return (1);
}

int get_end(char **save_data, char *buff, error_comter_t *error_comter_s,
data_t *data_s)
{
    if (get_len_array(save_data) == 3 && error_comter_s->is_next_end == 1) {
        if (error_comter_s->actual_part != 1) {
            my_printf("#rooms\n");
        }
        error_comter_s->actual_part = 1;
        error_comter_s->is_next_end = 0;
        error_comter_s->end += 1;
        if (is_room(buff) == 84) {
            data_s->is_error = 1;
            return (0);
        }
        my_printf("%s\n", buff);
        data_s->end = my_strdup(buff);
        save_every_rooms(data_s, buff);
        return (0);
    }
    if (find_end(buff, error_comter_s, data_s) == 0)
        return (0);
    if (error_comter_s->is_next_end == 1 || error_comter_s->is_next_start == 1)
        data_s->is_error = 1;
    return (1);
}
