/*
** EPITECH PROJECT, 2021
** my_str_is_alpha
** File description:
** return 1 if the string only contain alphabetical characters
*/

#include <stddef.h>

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0') {
        if ((str[i] < 65) || (str[i] > 122)) {
            return (0);
        } else if ((str[i] > 90) && (str[i] < 97)) {
            return (0);
        }
        i = i + 1;
    }
    return (1);
}
