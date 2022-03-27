/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy a string into another
*/

#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL)
        return (NULL);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
