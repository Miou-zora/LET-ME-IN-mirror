/*
** EPITECH PROJECT, 2021
** B-CPE-101-NAN-1-1-evalexpr-axel.idoux
** File description:
** get_str
*/

#include <stdlib.h>

int my_compute_power_rec(int, int);
int get_nbrlen(int);

char *my_itoa(int nb)
{
    int nb_len = get_nbrlen(nb);
    char *out_str = malloc(sizeof(char) * (nb_len + 2));
    int i = 0;
    int idx = 1;

    if (nb == -2147483648)
        return ("-2147483648");
    if (nb < 0) {
        out_str[0] = '-';
        i = 1;
        nb *= -1;
        nb_len++;
        idx++;
    }
    for (;i < nb_len; i++ / idx++)
        out_str[i] = ((nb / my_compute_power_rec(10, nb_len - idx)) % 10) + 48;
    out_str[i] = 0;
    return (out_str);
}
