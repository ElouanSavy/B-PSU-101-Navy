/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** return the square root of a number
*/

int my_compute_square_root(int nb)
{
    int result = 1;

    if (nb < 0) {
        return 0;
    }
    while (result * result != nb && result <= nb) {
        result = result + 1;
    }
    if (result > nb)
        return 0;
    return result;
}
