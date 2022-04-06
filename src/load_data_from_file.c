/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** load_data_from_file
*/

#include "lem_in.h"

void init_error_comter(error_comter_t *error_comter_s)
{
    error_comter_s->is_next_start = 0;
    error_comter_s->is_next_end = 0;
    error_comter_s->ants = 0;
    error_comter_s->start = 0;
    error_comter_s->end = 0;
}

int check_error_file(error_comter_t *error_comter_s)
{
    if (error_comter_s->ants > 1)
        return (84);
    if (error_comter_s->start > 1)
        return (84);
    if (error_comter_s->end > 1)
        return (84);
    return (0);
}

int analyse_get_value(char *buff, data_t *data_s,
error_comter_t *error_comter_s)
{
    char **save_data = NULL;
    char *tmp = my_strdup(buff);

    buff = remove_comments(buff);
    if (buff[0] == '\0')
        return (0);
    save_data = data_to_array_str(tmp, " ");
    if (is_str_nbr(buff) == 0) {
        error_comter_s->ants += 1;
        data_s->nb_ants = my_getnbr(buff);
    }
    if (get_len_array(save_data) == 3 && error_comter_s->is_next_start == 1) {
        error_comter_s->is_next_start = 0;
        error_comter_s->start += 1;
        data_s->start = my_strdup(buff);
    }
    if (get_len_array(save_data) == 3 && error_comter_s->is_next_end == 1) {
        error_comter_s->is_next_end = 0;
        error_comter_s->end += 1;
        data_s->end = my_strdup(buff);
    }
    if (my_strcmp(buff, "##start\n") == 0)
        error_comter_s->is_next_start = 1;
    if (my_strcmp(buff, "##end\n") == 0)
        error_comter_s->is_next_end = 1;
    free(tmp);
    free(save_data);
    return (0);
}

int load_data_from_file(data_t *data_s)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    size_t buffsize = 0;
    char *buff = NULL;
    int is_error = 0;

    init_error_comter(error_comter_s);
    if (getline(&buff, &buffsize, stdin) == -1) {
        free(buff);
        return (84);
    }
    do {
        is_error = analyse_get_value(buff, data_s, error_comter_s);
        if (is_error == 84 || check_error_file(error_comter_s) == 84)
            return (84);
    } while (getline(&buff, &buffsize, stdin) != -1);
    free(buff);
    free(error_comter_s);
    return (0);
}
