/*
** EPITECH PROJECT, 2022
** B-CPE-200-NAN-2-1-lemin-timothee.lesellier
** File description:
** lem_in
*/

#include "lem_in.h"

void init_data(data_t *data_s)
{
    data_s->end = NULL;
    data_s->start = NULL;
    data_s->room_name = NULL;
    data_s->path = NULL;
    data_s->every_rooms = NULL;
    data_s->nb_ants = 0;
}

void free_data(data_t *data_s)
{
    free(data_s->end);
    free(data_s->start);
    free_array(data_s->path);
    free_array(data_s->room_name);
    free_array(data_s->every_rooms);
    free(data_s);
}

int lem_in(int ac, char **av)
{
    data_t *data_s = malloc(sizeof(data_t));
    list_t **tab_node;

    (void)av;
    if (!data_s)
        return (84);
    if (ac != 1) {
        my_putstr_error(TO_MUCH_ARG);
        free_data(data_s);
        return (84);
    }
    init_data(data_s);
    if (load_data_from_file(data_s) == 84) {
        free_data(data_s);
        return (84);
    }
    tab_node = build_link(data_s);
    char ***temp = get_all_path(tab_node[0], data_s->end, tab_node);
    for (int i = 0; temp[i]; i++) {
        print_array_str(temp[i]);
        my_printf("\n");
    }
    display_info(data_s);
    free_tab_node(tab_node);
    free_data(data_s);
    return (0);
}
