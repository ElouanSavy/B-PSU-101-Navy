/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swp two number
*/

void my_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
