/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** my_show_word_array
*/

#include <stdio.h>

void my_putchar(char c);

void my_putstr(char *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    if (tab == NULL)
        return (84);
    while (tab[i] != '\0') {
        my_putstr(tab[i]);
        my_putchar('\n');
        i = i + 1;
    }
    return (0);
}
