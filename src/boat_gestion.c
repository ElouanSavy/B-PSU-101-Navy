/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** boat_gestion
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/my/my.h"
#include "../include/map_handling.h"

void is_a_boat(int i, char *coord, char nb, char **map)
{
    for (int j = 0; j < 8; j++) {
        if (i >= coord[2] - 65 && i <= coord[5] - 65 \
        && j >= coord[3] - 49 && j <= coord[6] - 49)
            map[j][i] = nb;
    }
}

void put_in_map(char **map, char *coord, char nb)
{
    for (int i = 0; i < 8; i++) {
        is_a_boat(i, coord, nb, map);
    }
}

int error_check(char *line, int i)
{
    if (line[2] != line[5] && line[3] != line[6]) {
        return 84;
    }
    if (line[2] == line[5] && abs_val(line[3] - line[6]) + 1 != line[0] - 48) {
        return 84;
    }
    if (line[3] == line[6] && abs_val(line[2] - line[5]) + 1 != line[0] - 48) {
        return 84;
    }
    if (i + 1 != line[0] - 48) {
        return 84;
    }
    if (line[1] != ':' || line[4] != ':') {
        return 84;
    }
    return 0;
}

int update_map(char **map, char *file)
{
    FILE *stream = fopen(file, "r");
    if (!stream)
        return 84;
    ssize_t len = 7;
    char *line_buffer = malloc(sizeof(char) * 7);
    for (int i = 1; i < 5; i++) {
        getline(&line_buffer, &len, stream);
        if (error_check(line_buffer, i) == 0)
            put_in_map(map, line_buffer, i + 49);
        else
            return 84;
    }
    if (getline(&line_buffer, &len, stream) != -1) {
        return 84;
    }
    fclose(stream);
    return 0;
}
