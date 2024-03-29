/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_name_path
*/

#include "lem_in.h"

int check_room_name(data_t *data_s, int is_new_name, char *temp)
{
    if (data_s->room_name == NULL)
        return (0);
    for (int i = 0; data_s->room_name[i] != NULL; i++)
        if (my_strcmp(temp, data_s->room_name[i]) == 0)
            is_new_name += 1;
    return (is_new_name);
}

int check_sec_name(char **tmp, char *save, data_t *data_s)
{
    int is_new_name = 0;
    char *temp = my_strdup(tmp[1]);

    is_new_name = check_room_name(data_s, is_new_name, temp);
    if (my_strcmp(temp, data_s->start) == 0)
        is_new_name += 1;
    if (my_strcmp(temp, data_s->end) == 0)
        is_new_name += 1;
    if (is_new_name == 0) {
        free(tmp);
        free(save);
        free(temp);
        my_putstr_error(NEW_NAME);
        return (84);
    }
    free(temp);
    return (0);
}

int is_new_name_null(char **tmp, char *save, int is_new_name)
{
    if (is_new_name == 0) {
        free(tmp);
        free(save);
        my_putstr_error(NEW_NAME);
        return (84);
    }
    return (0);
}

int check_path_name(data_t *data_s, char *path)
{
    char *save = my_strdup(path);
    char **tmp = data_to_array_str(save, "-");
    int is_new_name = 0;

    if (get_len_array(tmp) != 2)
        return (free_and_return(save, tmp, 84, NO_NUMBER));
    is_new_name = check_room_name(data_s, is_new_name, tmp[0]);
    if (my_strcmp(tmp[0], data_s->start) == 0)
        is_new_name += 1;
    if (my_strcmp(tmp[0], data_s->end) == 0)
        is_new_name += 1;
    if (is_new_name_null(tmp, save, is_new_name) == 84)
        return (84);
    if (check_sec_name(tmp, save, data_s) == 84)
        return (84);
    return (free_and_return(save, tmp, 0, NULL));
}
