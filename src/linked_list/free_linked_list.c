/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** free_linked_list
*/

#include "linked_list.h"

void free_tab_node(list_t **tab_node)
{
    for (int i = 0; tab_node[i] != NULL; i++) {
        free(tab_node[i]->next);
        free(tab_node[i]);
    }
    free(tab_node);
}
