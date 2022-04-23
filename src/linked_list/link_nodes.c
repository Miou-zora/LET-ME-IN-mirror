/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** link_nodes
*/


#include "lem_in.h"

list_t *get_address_by_name(list_t **tab_node, char *name)
{
    for (int i = 0; tab_node[i] != NULL; i++) {
        if (my_strcmp(tab_node[i]->name, name) == 0) {
            return (tab_node[i]);
        }
    }
    return (NULL);
}

void add_new_pointers(list_t *node, list_t *new_pointer)
{
    int i = 0;

    for (; node->next[i] != NULL;) {
        if (my_strcmp(node->next[i]->name, new_pointer->name) == 0) {
            return;
        }
        i++;
    }
    node->next[i] = new_pointer;
}

int link_node_on_str(list_t **tab_node, char *name)
{
    char *name_dup = my_strdup(name);
    char **nodes = NULL;
    list_t *node1 = NULL;
    list_t *node2 = NULL;

    if (name_dup == NULL) {
        return (-1);
    }
    nodes = data_to_array_str(name_dup, "-");
    if (nodes == NULL) {
        free(name_dup);
        return (-1);
    }
    if (my_strcmp(nodes[0], nodes[1]) == 0) {
        free(nodes);
        free(name_dup);
        return (0);
    }
    node1 = get_address_by_name(tab_node, nodes[0]);
    node2 = get_address_by_name(tab_node, nodes[1]);
    add_new_pointers(node1, node2);
    add_new_pointers(node2, node1);
    free(nodes);
    free(name_dup);
    return (0);
}

int link_all_nodes(list_t **tab_node, char **path)
{
    for (int i = 0; path[i] != NULL; i++) {
        if (link_node_on_str(tab_node, path[i]) == -1) {
            return (-1);
        }
    }
    return (0);
}
