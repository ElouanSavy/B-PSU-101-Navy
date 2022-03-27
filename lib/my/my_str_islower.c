/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** return 1 if a string is only composed of lower characters
*/

#include <stddef.h>

int my_str_islower(char const *str)
{
    int i = 0;

    if(str == NULL)
        return (84);
    if (str[0] == '\0') {
        return (1);
    }
    while (str[i] != '\0') {
        if ((str[i] < 97) || (str[i] > 122)) {
            return (0);
        }
        i = i + 1;
    }
    return (1);
}
