/*
** EPITECH PROJECT, 2021
** my_str_isprintable.c
** File description:
** return 1 if the string is printable
*/

#include <stdio.h>

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    if (str[0] == '\0') {
        return (1);
    }
    while (str[i] != '\0') {
        if ((str[i] < 32 && str[i] > 13) || (str[i] == 127)) {
            return (0);
        } else if (str[i] > 0 && str[i] < 7) {
            return (0);
        }
        i = i + 1;
    }
    return (1);
}
