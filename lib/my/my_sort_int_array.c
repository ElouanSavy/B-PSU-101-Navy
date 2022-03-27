/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** sort an array of int
*/

void check_number(int *array, int size,  int index)
{
    int i = index;
    int tmp = 0;

    while (i < size) {
        if (array[index] > array[i]) {
            tmp = array[index];
            array[index] = array[i];
            array[i] = tmp;
        }
        i = i + 1;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;

    while (i < size - 1) {
        check_number(array, size, i);
        i = i + 1;
    }
}
