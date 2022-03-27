/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** my_str_to_word_arary
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n);

int is_alphanumeric(char c)
{
    if ((c > 64 && c < 91) || (c > 96 && c < 123) || (c > 47 && c < 58)) {
        return (1);
    } else {
        return (0);
    }
}

int count_word(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        if (is_alphanumeric(str[i]) && !is_alphanumeric(str[i + 1])) {
            counter += 1;
        }
        i += 1;
    }
    return (counter);
}

char *save_word(char const *str, int *i)
{
    char *tmp = NULL;
    int min = *i;
    int max = *i;
    int j = 0;

    while (is_alphanumeric(str[*i])) {
        max += 1;
        *i += 1;
    }
    tmp = malloc(sizeof(char) * ((max - min) + 1));
    if (str[*i] == '\0')
        *i -= 1;
    while (min < max) {
        tmp[j] = str[min];
        min += 1;
        j += 1;
    }
    tmp[j] = '\0';
    return (tmp);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int index = 0;
    char **tab = NULL;
    int size = 0;

    if (str == NULL)
        return (NULL);
    size = count_word(str);
    tab = malloc(sizeof(char *) * (size + 1));
    if (tab == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (is_alphanumeric(str[i])) {
            tab[index] = save_word(str, &i);
            index += 1;
        }
        i += 1;
    }
    tab[size] = NULL;
    return (tab);
}
