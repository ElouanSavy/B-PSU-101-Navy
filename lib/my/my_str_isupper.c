/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** return 1 if a string is only composed of upper characters
*/

#include <stdio.h>

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    while (str[i] != '\0') {
        if ((str[i] < 65) || (str[i] > 90)) {
            return (0);
        }
        i = i + 1;
    }
    return (1);
}
