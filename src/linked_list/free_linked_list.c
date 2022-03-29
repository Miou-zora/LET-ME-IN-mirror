/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** free_linked_list
*/

#include "linked_list.h"

void free_struct(list_t *list)
{
    while (list->next != NULL) {
        list = list->next;
        free(list->prev);
    }
    free(list);
}
