/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** lem_in
*/

#ifndef LEM_IN_H_
    #define LEM_IN_H_

/******************************includes****************************************/

    #include "my.h"
    #include "linked_list.h"
    #include <stdio.h>

/******************************structurs***************************************/

    typedef struct data {
        int nb_ants;
        char *start;
        char *end;
        char **room_name;
        char **path;
    } data_t;

    typedef struct error_comter {
        int is_next_start;
        int is_next_end;
        int ants;
        int start;
        int end;
    } error_comter_t;

/******************************fonctions***************************************/


//!project fonction

int lem_in(int ac, char **av);
int load_data_from_file(data_t *data);

//?get value
int get_start(char **save_data, char *buff, error_comter_t *error_comter_s,
data_t *data_s);
int get_end(char **save_data, char *buff, error_comter_t *error_comter_s,
data_t *data_s);
void get_rooms_and_tunnels(char **save_data, char *buff, data_t *data_s);
int analyse_get_value(char *buff, data_t *data_s,
error_comter_t *error_comter_s);
void save_tunnel(data_t *data_s, char *buff);
void save_room(data_t *data_s, char *buff);

//!error handling
int check_error_file(error_comter_t *error_comter_s);
int check_error_file_end(error_comter_t *error_comter_s);

//!useful fonctions

int is_str_nbr(char *str);
char *remove_comments(char *buff);

/******************************enum********************************************/

/******************************global var**************************************/

/******************************define******************************************/

#endif /* !LEM_IN_H_ */
