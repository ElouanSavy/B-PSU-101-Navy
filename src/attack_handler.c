/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** attack_handler
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

char *get_coord(void)
{
    char *buffer = malloc(sizeof(char) * 4);
    int i = 0;

    my_printf("attack: ");
    read(0, buffer, 3);
    while (i < 4) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
        i += 1;
    }
    buffer[3] = '\0';
    return (buffer);
}

void display_attack_results(char **enemy_map, char *user_input)
{
    if (enemy_signal.nb_usr1) {
        my_printf("%s: hit\n\n", user_input);
        update_by_char(enemy_map, user_input, 'x');
    } else {
        my_printf("%s: missed\n\n", user_input);
        update_by_char(enemy_map, user_input, 'o');
    }
}

int attack(char **enemy_map)
{
    char *user_input;

    user_input = get_coord();
    if (!is_valid_coord(user_input)) {
        my_printf("wrong position\n");
        attack(enemy_map);
        return 0;
    }
    send_signal(user_input[0] - 64);
    pause();
    send_signal(user_input[1] - 48);
    reset_signal();
    pause();
    display_attack_results(enemy_map, user_input);
    return (0);
}
