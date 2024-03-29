/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** save_data_and_rooms
*/

#include "lem_in.h"

void save_every_rooms(data_t *data_s, char *buff)
{
    char **save = NULL;
    int i = 0;

    if (data_s->every_rooms != NULL)
        save = my_arraydup(data_s->every_rooms);
    free_array(data_s->every_rooms);
    data_s->every_rooms = my_calloc((get_len_array(save) + 2), sizeof(char *));
    if (save != NULL) {
        for (i = 0; save[i] != NULL; i++)
            data_s->every_rooms[i] = my_strdup(save[i]);
        data_s->every_rooms[i] = my_strdup(buff);
        data_s->every_rooms[i + 1] = NULL;
    } else {
        data_s->every_rooms[i] = my_strdup(buff);
        data_s->every_rooms[i + 1] = NULL;
    }
    free_array(save);
}

void save_room(data_t *data_s, char *buff)
{
    char **save = NULL;
    int i = 0;

    if (data_s->room_name != NULL)
        save = my_arraydup(data_s->room_name);
    free_array(data_s->room_name);
    data_s->room_name = my_calloc((get_len_array(save) + 2), sizeof(char *));
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
    data_s->path = my_calloc((get_len_array(save) + 2), sizeof(*(data_s->path)));
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
