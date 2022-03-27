/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int len = my_strlen(src);

    if (src == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (len + 1));
    while (i < len) {
        str[i] = src[i];
        i = i + 1;
    }
    str[i] = '\0';
    return (str);
}
