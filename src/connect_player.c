/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** connect_player
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

#include "my.h"
#include "navy.h"

int connect_player(void)
{
    my_printf("Waiting for enemy connection...\n\n");
    pause();
    if (enemy_signal.nb_usr1 == 1) {
        enemy_signal.nb_usr1 = 0;
        my_printf("enemy connected\n\n");
        return (1);
    }
    return (0);
}

int confirm_connection(char *pid)
{
    return (kill(my_getnbr(pid), SIGUSR1));
}
