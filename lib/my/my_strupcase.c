/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** rewrite a string with uper charactere
*/

#include <string.h>

char *my_strupcase(char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] < 123 && str[i] > 96) {
            str[i] = str[i] - 32;
        }
        i = i + 1;
    }
    return (str);
}
