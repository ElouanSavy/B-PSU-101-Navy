/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** my_strncat
*/

#include <stdio.h>

int my_strlen(char *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int dest_len = my_strlen(dest);

    if (src == NULL)
        return (NULL);
    while (i < nb) {
        dest[i + dest_len] = src[i];
        i = i + 1;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
