/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** save_data_and_rooms
*/

#include "lem_in.h"

void free_array(char **arr)
{
    if (arr != NULL)
        for (int j = 0; arr[j] != NULL; j++)
            free(arr[j]);
    free(arr);
}

void save_room(data_t *data_s, char *buff)
{
    char **save = NULL;
    int i = 0;

    if (data_s->room_name != NULL)
        save = my_arraydup(data_s->room_name);
    free_array(data_s->room_name);
    data_s->room_name = my_calloc(sizeof(char *),
    (get_len_array(save) + 2));
    if (save != NULL) {
        for (i = 0; save[i] != NULL; i++)
            data_s->room_name[i] = my_strdup(save[i]);
        data_s->room_name[i] = my_strdup(buff);
        data_s->room_name[i + 1] = NULL;
    } else {
        data_s->room_name[i] = my_strdup(buff);
        data_s->room_name[i + 1] = NULL;
    }
    free_array(save);
}

void save_tunnel(data_t *data_s, char *buff)
{
    char **save = NULL;
    int i = 0;

    if (data_s->path != NULL)
        save = my_arraydup(data_s->path);
    free_array(data_s->path);
    data_s->path = my_calloc(sizeof(char *),
    (get_len_array(save) + 2));
    if (save != NULL) {
        for (i = 0; save[i] != NULL; i++)
            data_s->path[i] = my_strdup(save[i]);
        data_s->path[i] = my_strdup(buff);
        data_s->path[i + 1] = NULL;
    } else {
        data_s->path[i] = my_strdup(buff);
        data_s->path[i + 1] = NULL;
    }
    free_array(save);
}
