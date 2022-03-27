/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** utils
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/map_handling.h"
#include "../lib/my/my.h"

int check_win_condition(char *map)
{
    for (int j = 0; j < 8; j++) {
        if (map[j] > '1' && map[j] < '6')
            return 0;
    }
    return 1;
}

int check_win(char **map)
{
    for (int i = 0; i < 8; i++) {
        if (check_win_condition(map[i]) == 0)
            return 0;
    }
    return 1;
}

int abs_val(int value)
{
    if (value < 0)
        value = value * -1;
    return value;
}

int update_by_char(char **map, char *coord, char new_char)
{
    if (my_strlen(coord) != 2)
        return 84;
    int column = coord[0] - 65;
    int line = coord[1] - 49;
    if (column <= 7 && column >= 0 && line >= 0 && line <= 7) {
        map[line][column] = new_char;
    }
}
