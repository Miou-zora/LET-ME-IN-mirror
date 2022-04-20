/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** build_tab_node
*/

#include "lem_in.h"

int is_end_declaration_name(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            return (0);
        }
    }
    return (1);
}

size_t get_size_malloc_tab(char **info)
{
    size_t size = 0;

    if (info == NULL)
        return (size);
    for (int i = 0; info[i] != NULL; i++) {
        if (is_end_declaration_name(info[i]) == 1) {
            size++;
        } else {
            return (size);
        }
    }
    return (size);
}

int build_each_node(list_t **tab_node, data_t *data, char **info)
{
    list_t *temp;
    int j = 2;
    tab_node[0] = malloc(sizeof(list_t));
    tab_node[1] = malloc(sizeof(list_t));

    if (tab_node[0] == NULL || tab_node[1] == NULL) {
        return (-1);
    }
    tab_node[0]->name = data->start;
    tab_node[1]->name = data->end;
    if (info == NULL)
        return (0);
    for (int i = 0; info[i] != NULL; i++, j++) {
        temp = malloc(sizeof(list_t));
        if (temp == NULL) {
            return (-1);
        }
        temp->name = info[i];
        temp->visited = false;
        tab_node[j] = temp;
    }
    return (0);
}

list_t **build_tab_node(data_t *data, char **info)
{
    size_t nb_node = get_size_malloc_tab(info);
    list_t **tab_node = malloc(sizeof(list_t *) * (nb_node + 3));

    if (tab_node == NULL)
        return (NULL);
    if (build_each_node(tab_node, data, info) == -1) {
        return (NULL);
    }
    tab_node[nb_node + 2] = NULL;
    return (tab_node);
}
