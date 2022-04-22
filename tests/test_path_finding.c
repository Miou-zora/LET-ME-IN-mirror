/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** test_path_finding
*/

#include "lem_in.h"

#include <criterion/criterion.h>

// typedef struct data {
//     int nb_ants;
//     char *start;
//     char *end;
//     char **room_name;
//     char **path;
//     char **every_rooms;
// } data_t;

data_t *generate_data(void)
{
    data_t *data_s = malloc(sizeof(*data_s));
    char **room_name = my_calloc(8, sizeof(*room_name));
    char **path = my_calloc(14, sizeof(*path));
    int i = 0;

    if (data_s != NULL && (room_name == NULL || path == NULL)) {
        free(data_s);
    }
    if (room_name != NULL && (data_s == NULL || path == NULL)) {
        free(room_name);
    }
    if (path != NULL && (data_s == NULL || room_name == NULL)) {
        free(path);
    }
    if (path == NULL || room_name == NULL || data_s == NULL) {
        return (NULL);
    }
    room_name[0] = my_strdup("2");
    room_name[1] = my_strdup("3");
    room_name[2] = my_strdup("4");
    room_name[3] = my_strdup("5");
    room_name[4] = my_strdup("6");
    room_name[5] = my_strdup("7");
    path[0] = my_strdup("0-7");
    path[1] = my_strdup("4-3");
    path[2] = my_strdup("5-2");
    path[3] = my_strdup("7-6");
    path[4] = my_strdup("4-2");
    path[5] = my_strdup("2-1");
    path[6] = my_strdup("3-5");
    path[7] = my_strdup("7-2");
    path[8] = my_strdup("7-4");
    path[9] = my_strdup("1-3");
    path[10] = my_strdup("6-5");
    path[11] = my_strdup("5-0");
    data_s->nb_ants = 18;
    data_s->start = my_strdup("1");
    data_s->end = my_strdup("0");
    data_s->room_name = room_name;
    data_s->path = path;
    data_s->every_rooms = NULL;
    return (data_s);
}

Test(get_all_path, normal_case)
{
    data_t *data_s = generate_data();
    list_t **tab_node;

    if (data_s == NULL) {
        return;
    }
    tab_node = build_link(data_s);
    char ***paths = get_all_path(tab_node[0], data_s->end, tab_node);
}

Test(get_all_path, no_path)
{
    data_t *data_s = generate_data();
    list_t **tab_node;

    if (data_s == NULL) {
        return;
    }
    free(data_s->path[0]);
    data_s->path[0] = my_strdup("2-7");
    free(data_s->path[11]);
    data_s->path[11] = my_strdup("5-2");
    tab_node = build_link(data_s);
    char ***paths = get_all_path(tab_node[0], data_s->end, tab_node);
    cr_assert_null(paths);
}

Test(update_shortest_path, with_null_value)
{
    update_shortest_path(NULL, NULL);
}

Test(get_shortest_path_rec, with_null_value)
{
    list_t *list = my_calloc(1, sizeof(*list));
    char **temp = NULL;

    if (list == NULL) {
        return;
    }
    list->visited = true;
    temp = get_shortest_path_rec(list, 0, NULL);
    if (temp != NULL) {
        free(temp);
    }
    list->visited = false;
    list->next = NULL;
    temp = get_shortest_path_rec(list, 0, NULL);
    if (temp != NULL) {
        free(temp);
    }
    list->next = my_calloc(1, sizeof(*list));
    if (list->next == NULL) {
        free(list);
        return;
    }
    temp = get_shortest_path_rec(NULL, 0, NULL);
    if (temp != NULL) {
        free(temp);
    }
    temp = get_shortest_path_rec(list, 0, NULL);
    if (temp != NULL) {
        free(temp);
    }
}

Test(find_next, with_null_value)
{
    list_t *list = my_calloc(1, sizeof(*list));
    char *str = my_strdup("test");

    if (list == NULL || str == NULL) {
        if (list != NULL) {
            free(list);
        }
        if (str != NULL) {
            free(str);
        }
        return;
    }
    list->next = my_calloc(1, sizeof(*list));
    if (list->next == NULL) {
        free(list);
        return;
    }
    find_next(NULL, NULL);
    find_next(list, NULL);
    find_next(list, str);
    free(list->next);
    list->next = NULL;
    find_next(list, NULL);
}

Test(remove_path, with_null_value)
{
    char **room_name = my_calloc(8, sizeof(*room_name));
    list_t *list = my_calloc(1, sizeof(*list));

    if (room_name == NULL || list == NULL) {
        if (room_name != NULL) {
            free(room_name);
        }
        if (list != NULL) {
            free(list);
        }
        return;
    }
    room_name[0] = my_strdup("2");
    remove_path(room_name, list);
    room_name[1] = my_strdup("3");
    room_name[2] = my_strdup("4");
    room_name[3] = my_strdup("5");
    room_name[4] = my_strdup("6");
    room_name[5] = my_strdup("7");
    remove_path(room_name, NULL);
    remove_path(NULL, NULL);
}