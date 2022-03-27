/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** return if a number is prime or not
*/

int my_is_prime(int nb)
{
    int is_prime = 1;
    int i = 2;
    if ((nb % 2 == 0) && (nb != 2)) {
        return (0);
    } else if (nb < 2) {
        return (0);
    }
    while (i <= (nb / 2) && is_prime == 1) {
        if (nb % i == 0 && i != nb ) {
            is_prime = 0;
        }
        i = i + 1;
    }
    return (is_prime);
}
