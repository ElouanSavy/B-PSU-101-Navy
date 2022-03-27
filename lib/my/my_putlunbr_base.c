/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-elouan.savy-camaret
** File description:
** my_putlunbr_base
*/

#include "my.h"

unsigned long int find_lupower(long int len, unsigned long int nbr)
{
    unsigned long int divisor = len;

    while ((nbr / divisor) >= len) {
        divisor *= len;
    }
    return (divisor);
}

int my_putlunbr_base(long unsigned int nbr, char const *base)
{
    long int base_length = my_strlen(base);
    unsigned long int tmp = 0;

    if (base == NULL)
        return (84);
    if (nbr < 0) {
        my_putchar('-');
        nbr = - nbr;
    }
    tmp = find_lupower(base_length, nbr);
    while (nbr > 0) {
        my_putchar(base[nbr / tmp]);
        nbr = nbr % tmp;
        tmp = tmp / base_length;
    }
    return (0);
}
