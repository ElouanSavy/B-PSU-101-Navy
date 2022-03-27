/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** return 1 if the string is only composed of num
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    while (str[i] != '\0') {
        if ((str[i] < 48) || (str[i] > 57)) {
            return (0);
        }
        i = i + 1;
    }
    return (1);
}
