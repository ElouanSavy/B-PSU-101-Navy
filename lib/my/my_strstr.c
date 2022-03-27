/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** find the first occurence of a string in another string
*/

#include <stddef.h>

int check_str(char *str, char const *to_find)
{
    int i = 0;
    int is_same = 1;

    while (to_find[i] != '\0') {
        if (str[i] != to_find[i]) {
            is_same = 0;
        }
        i = i + 1;
    }
    return (is_same);
}

char *my_strstr(char *str , char const *to_find)
{
    int i = 0;

    if (str == NULL || to_find == NULL)
        return (NULL);
    if (to_find[0] == '\0') {
        return (str);
    }
    while (str[i] != '\0') {
        if (str[i] == to_find[0] && check_str(&str[i], to_find)) {
            return (&str[i]);
        }
        i = i + 1;
    }
    return (NULL);
}
