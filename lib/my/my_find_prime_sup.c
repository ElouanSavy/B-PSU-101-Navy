/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** find the next prime number
*/

int my_find_prime_sup(int nb)
{
    int result = nb;
    int is_prime = 1;
    int i = 2;

    if (nb < 2) {
        return (2);
    }
    while (i <= (nb / 2) && is_prime == 1) {
        if (nb % i == 0 && i != nb ) {
            is_prime = 0;
        }
        i = i + 1;
    }
    if (!is_prime)
        result = my_find_prime_sup(nb + 1);
    return (result);
}
