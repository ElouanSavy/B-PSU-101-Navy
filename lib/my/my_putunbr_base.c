/*
** EPITECH PROJECT, 2021
** my_put_nbr_base
** File description:
** convert number in a given base
*/

#include "my.h"

void count_print_digits(char digit, int *size)
{
    my_putchar(digit);
    *size += 1;
}

int find_upower(int len, unsigned int nbr, int *prec_pwr, int *size)
{
    int power = 0;

    while (nbr >= len) {
        power += 1;
        nbr = nbr / len;
    }
    if (((*prec_pwr) - (power) > 1) && *prec_pwr != 0) {
        print_zero((*prec_pwr) - (power) - 1, size);
    }
    *prec_pwr = power;
    return (my_compute_power_rec(len, power));
}

int my_putunbr_base(unsigned int nbr, char const *base)
{
    int base_length = my_strlen(base);
    int tmp = 0;
    int prec_pwr = 0;
    int size = 0;

    if (nbr == 0) {
        my_put_nbr(0);
        return (size);
    }
    while (nbr > 0) {
        tmp = find_upower(base_length, nbr, &prec_pwr, &size);
        count_print_digits(base[nbr / tmp], &size);
        nbr = nbr % tmp;
    }
    while (tmp != 1) {
        count_print_digits('0', &size);
        tmp = tmp / base_length;
    }
    return (size);
}
