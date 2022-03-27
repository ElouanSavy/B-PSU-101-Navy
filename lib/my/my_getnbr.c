/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** convert a number given by string to an int
*/

#include <stdio.h>

int set_min_and_max(int i, char const *str, int *min, int *max)
{
    int iterate = 1;
    if (*min == -1) {
        *min = i;
    }
    if (str[i + 1] == '\0' || str[i + 1] > 57 || str[i + 1] < 48) {
        iterate = 0;
        *max = i;
    }
    return (iterate);
}

void get_number_index(char const *str, int *min, int *max)
{
    int i = 0;
    int iterate = 1;

    while (iterate && str[i] != '\0') {
        if (str[i] > 47 && str[i] < 58) {
            iterate = set_min_and_max(i, str, min, max);
        }
        i = i + 1;
    }
}

long convert_to_int(char const *str, int min, int max, int negative)
{
    int i = max;
    long m = 1;
    long number = 0;

    while (i >= min) {
        number = number + ((str[i] - 48) * m);
        m = m * 10;
        i = i - 1;
    }
    if (negative % 2 != 0) {
        number = -number;
    }
    if (number > 2147483647 || number < -2147483647) {
        number = 0;
    }
    return (number);
}

int count_negative(char const *str, int min)
{
    int i = 0;
    int count = 0;

    while (i < min) {
        if (str[i] == '-') {
            count = count + 1;
        }
        i = i + 1;
    }
    return (count);
}

int my_getnbr(char const *str)
{
    int min = -1;
    int max = 0;
    long number = 0;
    int negative = 0;

    if (str == NULL)
        return (84);
    get_number_index(str, &min, &max);
    if (min == -1) {
        return (0);
    } else {
        negative = count_negative(str, min);
        number = convert_to_int(str, min, max, negative);
    }
    return (number);
}
