/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/

#include <stdio.h>

int my_strlen(char *str);

char *my_strcat(char *dest , char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);

    if (src == NULL)
        return (NULL);
    while (src[i] != '\0') {
        dest[i + dest_len] = src[i];
        i = i + 1;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
