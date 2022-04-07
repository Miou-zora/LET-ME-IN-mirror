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
int error_data(data_t *data_s);

//!useful fonctions

int is_str_nbr(char *str);
char *remove_comments(char *buff);
void free_array(char **arr);
void my_putstr_error(char *error);
int free_and_return(char *tmp, char **save_data, int nb);

/******************************enum********************************************/

/******************************global var**************************************/

/******************************define******************************************/

    #define NO_ANTS "No ants found in the file :\nexit code 84\n"
    #define NO_START "No start found in the file :\nexit code 84\n"
    #define NO_END "No end found in the file :\nexit code 84\n"
    #define TO_MUCH_ANTS "To much ants found in the file :\n\
    exit code 84\n"
    #define TO_MUCH_START "To much start found in the file :\n\
    exit code 84\n"
    #define TO_MUCH_END "To much end found in the file :\nexit code 84\n"
    #define DASH_IN_NAME "dash found in room name:\nexit code 84\n"
    #define NO_NUMBER "caracter different than number found in room positions :\
    \nexit code 84\n"
    #define NEGATIVE_ANTS "negative ants number found :\nexit code 84\n"
    #define TO_MUCH_DATA "To much data found on a line :\nexit code 84\n"
    #define TO_MUCH_ARG "To much arguments found no argument need :\n\
    exit code 84\n"
    #define EMPTY_FILE "Empty file detected :\nexit code 84\n"

#endif /* !LEM_IN_H_ */
