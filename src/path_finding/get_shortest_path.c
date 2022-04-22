/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror [WSL: Ubuntu]
** File description:
** get_shortest_path
*/

#include "lem_in.h"

int len_array_list(list_t **list)
{
    int i = 0;

    for (; list[i] != NULL; i++);
    return (i);
}

void update_shortest_path(char ***shortest_path, char **cursor)
{
    if (cursor != NULL && (*shortest_path == NULL ||
    get_len_array(cursor) < get_len_array(*shortest_path))) {
        if (*shortest_path != NULL) {
            free(*shortest_path);
        }
        *shortest_path = cursor;
    }
}

char **search_shortest_path(list_t *start, char *end_name, int size_matrix)
{
    char **cursor = NULL;
    char **shortest_path = NULL;

    for (int i = 0; start->next[i] != NULL; i++) {
        if (start->next[i]->visited == false) {
            cursor = get_shortest_path_rec(start->next[i], size_matrix,
            end_name);
            update_shortest_path(&shortest_path, cursor);
        }
    }
    return (shortest_path);
}

char **get_shortest_path_rec(list_t *start, int size_matrix, char *end_name)
{
    char **path = NULL;
    char **shortest_path = NULL;

    if (start == NULL || start->visited == true ||
    start->next == NULL || start->next[0] == NULL) {
        return (NULL);
    }
    if (my_strcmp(start->name, end_name) == 0) {
        path = my_calloc(size_matrix + 1, sizeof(*path));
        path[0] = start->name;
        return (path);
    }
    start->visited = true;
    shortest_path = search_shortest_path(start, end_name, size_matrix);
    if (shortest_path == NULL) {
        start->visited = false;
        return (NULL);
    }
    shortest_path[get_len_array(shortest_path)] = start->name;
    start->visited = false;
    return (shortest_path);
}

char ***get_all_path(list_t *start, char *end_name, list_t **all_list)
{
    int len_array = len_array_list(all_list) + 1;
    char ***all_path = my_calloc(len_array + 1, sizeof(*all_path));
    int i = 0;
    char **path = NULL;

    do {
        path = get_shortest_path_rec(start, len_array, end_name);
        if (path != NULL) {
            remove_path(path, start);
            all_path[i] = path;
            i++;
        }
    } while (path != NULL);
    if (i == 0) {
        free(all_path);
        return (NULL);
    }
    return (all_path);
}
