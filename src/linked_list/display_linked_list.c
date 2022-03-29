/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** display_linked_list
*/

#include "linked_list.h"

void display_pile(list_t *pile)
{
    list_t *temp = pile;

    while (temp != NULL) {
        my_put_nbr(temp->nb);
        temp = temp->next;
        my_putstr(" ");
    }
    my_putchar('\n');
}
