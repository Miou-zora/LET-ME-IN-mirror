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

int free_buff_and_return(char *buff, error_comter_t *error_comter_s, int nb)
{
    free(buff);
    free(error_comter_s);
    return (nb);
}

int load_data_from_file(data_t *data_s)
{
    error_comter_t *error_comter_s = malloc(sizeof(error_comter_t));
    size_t buffsize = 0;
    char *buff = NULL;
    int is_error = 0;

    init_error_comter(error_comter_s);
    if (getline(&buff, &buffsize, stdin) == -1) {
        my_putstr_error(EMPTY_FILE);
        return (free_buff_and_return(buff, error_comter_s, 84));
    }
    do {
        is_error = analyse_get_value(buff, data_s, error_comter_s);
        if (is_error == 84 || check_error_file(error_comter_s) == 84)
            return (free_buff_and_return(buff, error_comter_s, 84));
    } while (getline(&buff, &buffsize, stdin) != -1);
    if (check_error_file_end(error_comter_s) == 84 || error_data(data_s) == 84)
        return (free_buff_and_return(buff, error_comter_s, 84));
    return (free_buff_and_return(buff, error_comter_s, 0));
}
