/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** lem_in
*/

#ifndef LEM_IN_H_
    #define LEM_IN_H_

/*********************************************/

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
        char **every_rooms;
        int is_error;
    } data_t;

    typedef struct error_comter {
        int is_next_start;
        int is_next_end;
        int ants;
        int start;
        int end;
        int actual_part;
        int count_parts;
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
void get_rooms_and_tunnels(char **save_data, char *buff, data_t *data_s,
error_comter_t *error_comter_s);
int analyse_get_value(char *buff, data_t *data_s,
error_comter_t *error_comter_s);
void save_tunnel(data_t *data_s, char *buff);
void save_room(data_t *data_s, char *buff);

//!error handling
int check_error_file(data_t *data, char **file_data);
int error_data(data_t *data_s);
int check_path_name(data_t *data_s, char *path);
void save_every_rooms(data_t *data_s, char *buff);
int check_nbr_elements(error_comter_t *error_comter_s);
int check_error_file_end(error_comter_t *error_comter_s);
int is_room(char *data);

//!useful fonctions

int is_str_nbr(char *str);
char *remove_comments(char *buff);
void free_array(char **arr);
void my_putstr_error(char *error);
int free_and_return(char *tmp, char **save_data, int nb, char *message);
char *remove_space(char *buff);

//!linked_list functions

void display_tab_node(list_t **tab_node);
void free_tab_node(list_t **tab_node);
list_t **build_link(data_t *data);
list_t **build_tab_node(data_t *data, char **info);
int link_all_nodes(list_t **tab_node, char **path);

//!display info
void display_info(data_t *data);
int display_path(data_t *data, list_t **tab_node);
void append_int_list(int *list, int value);
int count_int_array(int *ants);
void display_movement(int **ants, char ***all_paths, int k);
int **get_ants(char ***all_paths, int nbr_paths, data_t *data);
int get_len_paths(char ***all_paths);
int get_pos_paths(char ***all_paths, int **ants, int nbr_paths);
int is_tunnel(char *buff);

//!path finding

char ***get_all_path(list_t *start, char *end_name, list_t **all_list);
void remove_path(char **path, list_t *node);
char **get_shortest_path_rec(list_t *start, int size_matrix, char *end_name);
void update_shortest_path(char ***shortest_path, char **cursor);
list_t *find_next(list_t *node, char *node_name);

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
    #define DASH_IN_NAME "Dash found in room name:\nexit code 84\n"
    #define NO_NUMBER "caracter different than number found in room positions :\
\nexit code 84\n"
    #define NEGATIVE_ANTS "No ants number found :\nexit code 84\n"
    #define TO_MUCH_DATA "To much data found on a line :\nexit code 84\n"
    #define TO_MUCH_ARG "To much arguments found no argument need :\n\
exit code 84\n"
    #define EMPTY_FILE "Empty file detected :\nexit code 84\n"
    #define NEW_NAME "New name detected in path :\nexit code 84\n"
    #define SAME_NAME "Same name detected many time :\nexit code 84\n"

#endif /* !LEM_IN_H_ */
