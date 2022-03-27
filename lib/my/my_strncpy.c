/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** copy n byte of a string
*/

#include <stdio.h>

int my_strlen(char *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(dest);

    if (src == NULL)
        return (NULL);
    while (i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
    if (n > len) {
        dest[i] = '\0';
    }
    return (dest);
}
