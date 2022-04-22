/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** remove_path
*/

#include "lem_in.h"

list_t *find_next(list_t *node, char *node_name)
{
    if (node == NULL || node->next == NULL || node_name == NULL) {
        return (NULL);
    }
    for (int j = 0; node->next[j] != NULL; j++) {
        if (my_strcmp(node->next[j]->name, node_name) == 0) {
            return (node->next[j]);
        }
    }
    return (NULL);
}

void remove_path(char **path, list_t *node)
{
    int len_array = 0;

    if (path == NULL || node == NULL) {
        return;
    }
    len_array = get_len_array(path);
    if (len_array - 2 < 0) {
        return;
    }
    node = find_next(node, path[len_array - 2]);
    for (int i = len_array - 2; i != 0 && node != NULL; i--) {
        node->visited = true;
        node = find_next(node, path[i - 1]);
    }

}
