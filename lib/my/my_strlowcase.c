/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** rewrite a string with low characters
*/

#include <stdio.h>

char *my_strlowcase(char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] < 91 && str[i] > 64) {
            str[i] = str[i] + 32;
        }
        i = i + 1;
    }
    return (str);
}
