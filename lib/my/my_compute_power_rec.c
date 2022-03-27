/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** return the power of a number
*/

int my_compute_power_rec(int nb , int p)
{
    int result = nb;

    if (p == 1)
        return (result);
    if (p == 0)
        return (1);
    if (nb == 0)
        return (0);
    if (p < 0)
        return (0);
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}
