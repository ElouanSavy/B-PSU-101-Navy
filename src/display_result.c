/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** display_result
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

int win_handler(char **map, int player_state)
{
    int win = check_win(map);
    reset_signal();
    send_win_signal(win, player_state);
    if (enemy_signal.nb_usr1 && !win)
        return (1);
    if (!enemy_signal.nb_usr1 && win)
        return (2);
    if (enemy_signal.nb_usr1 && win)
        return (3);
    return (0);
}

int display_result(int win)
{
    if (win == 1) {
        my_printf("I won\n");
        return (0);
    } else if (win == 2) {
        my_printf("Enemy won\n");
        return (1);
    } else {
        my_printf("No one won\n");
        return (0);
    }
}
