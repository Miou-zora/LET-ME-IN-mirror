/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** build_linked_list
*/

#include "linked_list.h"
#include "lem_in.h"

list_t **build_empty_array(int size)
{
    list_t **tab = my_calloc((size + 3), sizeof(*tab));

    return (tab);
}

int get_nb_connexion_node(char *node_name, char **conexion)
{
    int size = 0;

    for (int i = 0; conexion[i] != NULL; i++) {
        if (my_strstr(conexion[i], node_name) != NULL) {
            size++;
        }
    }
    return (size);
}

int build_tab_pointers(list_t **tab_node, data_t *data)
{
    for (int i = 0; tab_node[i] != NULL; i++) {
        tab_node[i]->next = build_empty_array(get_len_array(data->room_name));
        if (tab_node[i]->next == NULL) {
            return (-1);
        }
    }
    return (0);
}

list_t **build_link(data_t *data)
{
    list_t **tab_node = build_tab_node(data, data->room_name);

    if (tab_node == NULL) {
        return (NULL);
    }
    if (build_tab_pointers(tab_node, data) == -1) {
        return (NULL);
    }
    if (link_all_nodes(tab_node, data->path) == -1) {
        return (NULL);
    }
    return (tab_node);
}
