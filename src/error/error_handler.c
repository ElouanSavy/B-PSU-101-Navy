/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** error_handler
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

#include "my.h"
#include "navy.h"
#include "map_handling.h"

int verify_map(char **argv, int argc)
{
    if (init_map(argv[1]) == NULL && argc == 2)
        return 84;
    if (init_map(argv[2]) == NULL && argc == 3)
        return 84;
    return 0;
}

int verify_argv(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        return 84;
    return 0;
}

void free_buffer(void)
{
    char buffer[20];
    int ssize = 0;

    do {
        ssize = read(0, buffer, 20);
    } while (ssize == 20);
}

int is_valid_coord(char *coord)
{
    if (my_strlen(coord) > 2) {
        free_buffer();
        return (0);
    } else if (my_strlen(coord) < 2) {
        return (0);
    } else {
        if (coord[1] < '1' || coord[1] > '8')
            return (0);
        if (coord[0] < 'A' || coord[0] > 'H')
            return (0);
    }
    return (1);
}
