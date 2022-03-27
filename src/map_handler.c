/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** map_handler
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/map_handling.h"
#include "../lib/my/my.h"

void fill_map(char **map)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
    }
}

void display_map(char **boat_map)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 7; j++) {
            my_printf("%c ", boat_map[i][j]);
        }
        my_printf("%c", boat_map[i][7]);
        my_printf("\n");
    }
    my_printf("\n\0");
}

int update_own_map(char **map, char *coord)
{
    if (my_strlen(coord) != 2)
        return 84;
    int column = coord[0] - 65;
    int line = coord[1] - 49;
    if (column <= 7 && column >= 0 && line >= 0 && line <= 7) {
        if (map[line][column] == '.' || map[line][column] == 'o') {
            map[line][column] = 'o';
            return 0;
        } else {
            map[line][column] = 'x';
            return 1;
        }
    }
}

char **init_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 8);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    return map;
}

char **init_map(char *filepath)
{
    char **boat_map = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        boat_map[i] = malloc(sizeof(char) * 8);
    }
    fill_map(boat_map);
    if (update_map(boat_map, filepath) == 0)
        return boat_map;
    if (update_map(boat_map, filepath) == 84)
        return NULL;
}
