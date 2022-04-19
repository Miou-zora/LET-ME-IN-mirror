/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** The strcmp() function compares the two strings s1 and s2.
*/

int my_put_nbr(int);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
