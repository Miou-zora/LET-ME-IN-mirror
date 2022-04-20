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

void display_space_last_line(int **ants, int i, int j)
{
    if (ants[i + 1] != NULL && ants[i][j + 1] != 0) {
        my_putchar(' ');
    }
}

void display_line_movement(int **ants, char ***all_paths, int k, int i)
{
    for (int j = 0; ants[i][j] != 0; j++) {
        if ((k - j) <= get_len_array(all_paths[i]) && (k - j) > 1) {
            display_ends_movement(ants[i][j],
            all_paths[i][get_len_array(all_paths[i]) + j - k]);
            display_space_last_line(ants, i, j);
        }
    }
}

void display_movement(int **ants, char ***all_paths, int k)
{
    for (int i = 0; ants[i] != NULL; i++) {
        display_line_movement(ants, all_paths, k, i);
    }
}
