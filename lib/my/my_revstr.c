/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverse a string
*/

#include <stdio.h>

int my_strlen(char *str);

char *my_revstr(char *str)
{
    char tmp;
    int len = my_strlen(str);
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (i < (len / 2)) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
        i = i + 1;
    }
    return (str);
}
