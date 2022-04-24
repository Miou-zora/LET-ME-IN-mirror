/*
** EPITECH PROJECT, 2022
** LET-ME-IN-mirror
** File description:
** load_data_from_file
*/

#include "lem_in.h"

char *my_strcat_dup(char *str1, char *str2)
{
    char *res = my_calloc(my_strlen(str1) + my_strlen(str2) + 2, sizeof(char));
    size_t i = 0;

    if (res == NULL)
        return (NULL);
    for (size_t j = 0; str1[j] != '\0'; j++, i++) {
        res[i] = str1[j];
    }
    for (size_t j = 0; str2[j] != '\0'; j++, i++) {
        res[i] = str2[j];
    }
    res[i] = '\0';
    free(str1);
    return (res);
}

int free_buff_and_file(char *file, char *buff, char **file_data,
int return_value)
{
    free(file);
    free(buff);
    free(file_data);
    return (return_value);
}

int load_data_from_file(data_t *data_s)
{
    size_t buffsize = 0;
    char *buff = NULL;
    char *file = NULL;
    char **file_data = NULL;

    if (getline(&buff, &buffsize, stdin) == -1) {
        my_putstr_error(EMPTY_FILE);
        free(buff);
        return (84);
    }
    file = remove_space(remove_comments(my_strdup(buff)));
    while (getline(&buff, &buffsize, stdin) != -1) {
        buff = remove_space(remove_comments(buff));
        file = my_strcat_dup(file, buff);
    }
    file_data = data_to_array_str(file, "\n");
    if (check_error_file(data_s, file_data) == 84 || error_data(data_s) == 84)
        return (free_buff_and_file(file, buff, file_data, 84));
    return (free_buff_and_file(file, buff, file_data, 0));
}
