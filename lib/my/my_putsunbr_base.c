/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-elouan.savy-camaret
** File description:
** my_puthunbr_base
*/

#include "my.h"

int find_supower(int len, unsigned short int nbr, int *prec_pwr, int *size);

int find_supower(int len, unsigned short int nbr, int *prec_pwr, int *size)
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

int my_putsunbr_base(unsigned short int nbr, char const *base)
{
    int base_length = my_strlen(base);
    int tmp = 0;
    int prec_pwr = 0;
    int size = 0;

    if (nbr < 0) {
        count_print_digits('-', &size);
        nbr = - nbr;
    }
    while (nbr > 0) {
        tmp = find_supower(base_length, nbr, &prec_pwr, &size);
        count_print_digits(base[nbr / tmp], &size);
        nbr = nbr % tmp;
    }
    while (tmp != 1) {
        count_print_digits('0', &size);
        tmp = tmp / base_length;
    }
    return (size);
}
