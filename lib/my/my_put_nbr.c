/*
** EPITECH PROJECT, 2021
** my_putnbr
** File description:
** display a number
*/

void my_putchar(char c);

int find_divisor(int nb)
{
    int divisor = 1;

    while (nb / divisor > 9) {
        divisor = divisor * 10;
    }
    return (divisor);
}

int my_put_nbr(int nb)
{
    int divisor = 1;

    if (nb < 0) {
        divisor = find_divisor(-nb);
        nb = -nb;
        my_putchar('-');
    } else {
        divisor = find_divisor(nb);
    }
    while (divisor > 0) {
        my_putchar((nb / divisor) + 48);
        nb = nb % divisor;
        divisor = divisor / 10;
    }
    return (0);
}
