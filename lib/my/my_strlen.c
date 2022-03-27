/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** display the length of a string
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
