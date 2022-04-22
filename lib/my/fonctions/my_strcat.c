/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** A function that concatenates two strings.
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char *);

char *my_strcat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    for (; src[i]; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}

char *my_strcat_dup(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
    size_t i = 0;

    if (res == NULL)
        return (NULL);
    for (size_t j = 0; str1[j] != '\0'; j++, i++) {
        res[i] = str1[j];
    }
    res[i] = '\n';
    i++;
    for (size_t j = 0; str2[j] != '\n'; j++, i++) {
        res[i] = str1[j];
    }
    res[i] = '\0';
    free(str1);
    free(str2);
    return (res);
}