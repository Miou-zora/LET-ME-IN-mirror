/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-navy-quentin.brejoin
** File description:
** print_array_str
*/

#include "../include/my.h"
#include <stdlib.h>

void print_array_str(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        my_putstr(str[i]);
        my_putchar('\n');
    }
}
