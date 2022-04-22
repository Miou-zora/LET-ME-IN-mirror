/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** check_error_file
*/

#include "lem_in.h"

void display_ends_movement(int nbr_ant, char *room)
{
    my_printf("P%i-%s", nbr_ant, room);
}

void display_space_last_line(int *h)
{
    if ((*h) > 0) {
        my_putchar(' ');
    } else {
        (*h) += 1;
    }
}

void display_line_movement(int **ants, char ***all_paths, int *ki, int *h)
{
    for (int j = 0; ants[ki[1]][j] != 0; j++) {
        if ((ki[0] - j) <= get_len_array(all_paths[ki[1]]) && (ki[0] - j) > 1) {
            display_space_last_line(h);
            display_ends_movement(ants[ki[1]][j],
            all_paths[ki[1]][get_len_array(all_paths[ki[1]]) + j - ki[0]]);
        }
    }
}

void display_movement(int **ants, char ***all_paths, int k)
{
    int h = 0;
    int *ki = my_calloc(2, sizeof(*ki));

    if (ants == NULL || all_paths == NULL || ki == NULL) {
        if (ki != NULL) {
            free(ki);
        }
        return;
    }
    for (int i = 0; ants[i] != NULL; i++) {
        ki[0] = k;
        ki[1] = i;
        display_line_movement(ants, all_paths, ki, &h);
    }
    free(ki);
}
