/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** main
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

int main(int argc, char **argv)
{
    int player_state;
    char **map;
    char **enemy_map = init_empty_map();

    if (verify_map(argv, argc) == 84 || verify_argv(argc, argv) == 84)
        return 84;
    my_printf("my_pid : %d\n", getpid());
    redirect_signal();
    if (argc < 3) {
        player_state = 1;
        connect_player();
        map = init_map(argv[1]);
    } else {
        player_state = 2;
        confirm_connection(argv[1]);
        my_printf("successfully connected\n\n");
        map = init_map(argv[2]);
    }
    return (game_loop(map, enemy_map, player_state));
}
