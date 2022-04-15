/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_
    #include <unistd.h>
    #include "my.h"
    #include <stdlib.h>

    typedef struct list_s {
        char *name;
        struct list_s **next;
    } list_t;

#endif /* !LINKED_LIST_H_ */
