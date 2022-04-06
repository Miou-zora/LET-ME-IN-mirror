/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** lem_in
*/

#ifndef LEM_IN_H_
    #define LEM_IN_H_
    #include "linked_list.h"

/******************************structurs***************************************/

    typedef struct data {
        int nb_ants;
        char **room_name;
        char **path;
    } data_t;

/******************************fonctions***************************************/

void load_data_from_file(data_t *data);
int lem_in(int ac, char **av);


/******************************enum********************************************/

/******************************global var**************************************/

/******************************define******************************************/

#endif /* !LEM_IN_H_ */
