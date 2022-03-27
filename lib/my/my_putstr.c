/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** display all char of a string
*/

#include "my.h"
#include "unistd.h"

int my_putstr(char const *str)
{
    int size = my_strlen(str);

    if (str == NULL)
        return (84);
    write(1, str, size);
    return (0);
}
