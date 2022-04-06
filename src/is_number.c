/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** is_number
*/

int is_str_nbr(char *str)
{
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (84);
    return (0);
}
