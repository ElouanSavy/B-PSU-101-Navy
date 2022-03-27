/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** game_handler
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

char *receive_coord(void)
{
    char *coord = malloc(sizeof(char) * 3);

    while (enemy_signal.nb_usr2 == 0)
        pause();
    coord[0] = enemy_signal.nb_usr1 + 64;
    kill(enemy_signal.pid, SIGUSR2);
    reset_signal();
    while (enemy_signal.nb_usr2 == 0)
        pause();
    coord[1] = enemy_signal.nb_usr1 + 48;
    coord[2] = '\0';
    return (coord);
}

int send_response(int touched)
{
    if (touched)
        kill(enemy_signal.pid, SIGUSR1);
    else
        kill(enemy_signal.pid, SIGUSR2);
    return (0);
}

int game_handler(int player_state, char **map, char **enemy_map)
{
    int touched;

    reset_signal();
    if (player_state == 1) {
        attack(enemy_map);
    } else {
        my_printf("waiting for enemy's attack...\n");
        char *received_cords = receive_coord();
        touched = update_own_map(map, received_cords);
        if (touched == 1)
            my_printf("%s: hit\n\n");
        else
            my_printf("%s: missed\n\n");
        send_response(touched);
    }
}

void game_round(char **map, char **enemy_map, int player_state)
{
    game_handler(player_state, map, enemy_map);
    if (player_state == 2)
        player_state = 1;
    else
        player_state += 1;
    game_handler(player_state, map, enemy_map);
    if (player_state == 2)
        player_state = 1;
    else
        player_state += 1;
}

int game_loop(char **map, char **enemy_map, int player_state)
{
    int win = 0;

    my_printf("my positions:\n");
    display_map(map);
    my_printf("\nenemy's positions\n");
    display_map(enemy_map);
    while (win == 0) {
        game_round(map, enemy_map, player_state);
        my_printf("my positions:\n");
        display_map(map);
        my_printf("\nenemy's positions:\n");
        display_map(enemy_map);
        win = win_handler(map, player_state);
    }
    return (display_result(win));
}
