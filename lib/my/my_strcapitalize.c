/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** capitalize all word in a string
*/

#include <stdio.h>

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (str == NULL)
        return (NULL);
    if ((str[0] > 96) && (str[0] < 123)) {
        str[0] = str[0] - 32;
    }
    while (str[i] != '\0') {
        if ((str[i] == ' ') && (str[i + 1] > 96) && (str[i + 1] < 123)) {
            str[i + 1] = str[i + 1] - 32;
        } else if ((str[i - 1] != ' ') && (str[i] > 64) && (str[i] < 91)) {
            str[i] = str[i] + 32;
        }
        i = i + 1;
    }
    return (str);
}
