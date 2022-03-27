/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-elouan.savy-camaret
** File description:
** my_putlnbr_base
*/

#include "my.h"

void display_zero(int zero)
{
    int i = 0;

    while (i < zero) {
        my_putchar('0');
        i = i + 1;
    }
}

unsigned long int find_lpower(long int len, long int nbr)
{
    long int divisor = len;

    while ((nbr / divisor) >= len) {
        divisor *= len;
    }
    return (divisor);
}

int my_putlnbr_base(long int nbr, char const *base)
{
    long int base_length = my_strlen(base);
    unsigned long int tmp = 0;

    if (base == NULL)
        return (84);
    if (nbr < 0) {
        my_putchar('-');
        nbr = - nbr;
    }
    tmp = find_lpower(base_length, nbr);
    while (nbr > 0) {
        my_putchar(base[nbr / tmp]);
        nbr = nbr % tmp;
        tmp = tmp / base_length;
    }
    return (0);
}
