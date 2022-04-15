/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** build_linked_list
*/

#include "linked_list.h"
#include "lem_in.h"

int get_nb_connexion_node(char *node_name, char **conexion)
{
    int size = 0;
    (void) node_name;

    for (int i = 0; conexion[i] != NULL; i++) {
        if (my_strstr(node_name, conexion[i]) != 0) {
            size++;
        }
    }
    return (size);
}

list_t *get_address_by_name(list_t **tab_node, char *name)
{
    for (int i = 0; tab_node[i] != NULL; i++) {
        if (my_strcmp(tab_node[i]->name, name) == 0) {
            return (tab_node[i]);
        }
    }
    return (NULL);
}

int build_tab_pointers(list_t **tab_node, data_t *data)
{
    int nb_connexion = 0;

    for (int i = 0; tab_node[i] != NULL; i++) {
        nb_connexion = get_nb_connexion_node(tab_node[i]->name, data->path);
        tab_node[i]->next = malloc(sizeof(list_t *) * (nb_connexion + 1));
        if (tab_node[i]->next == NULL) {
            return (-1);
        }
        tab_node[nb_connexion + 1]->next = NULL;
    }
    return (0);
}

list_t **build_link(data_t *data)
{
    list_t **tab_node = build_tab_node(data, data->room_name);
    build_tab_pointers(tab_node, data);
    return (tab_node);
}
