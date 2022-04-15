/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** display_linked_list
*/

#include "linked_list.h"
#include "my.h"

void display_pile(list_t *pile)
{
    my_putstr(pile->name);
    my_putstr(" est relié à :");
    for (int i = 0; pile->next[i] != NULL; i++) {
        my_putstr(pile->next[i]->name);
        my_putstr(" ");
    }
    my_putchar('\n');
}

void display_tab_node(list_t **tab_node)
{
    if (tab_node == NULL)
        return;
    for (int i = 0; tab_node[i] != NULL; i++) {
        display_pile(tab_node[i]);
    }
}
