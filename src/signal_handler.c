/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** signal_handler
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

#include "my.h"
#include "navy.h"

enemy_t enemy_signal;

void handler(int sig, siginfo_t *si, void *unused)
{
    enemy_signal.pid = si->si_pid;

    if (si->si_signo == SIGUSR1) {
        enemy_signal.nb_usr1 += 1;
    } else if (si->si_signo == SIGUSR2) {
        enemy_signal.nb_usr2 += 1;
    }
}

int redirect_signal(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = &handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    return (0);
}

int send_signal(int nbr)
{
    for (int i = 0; i < nbr; i += 1) {
        usleep(300);
        kill(enemy_signal.pid, SIGUSR1);
    }
    usleep(300);
    kill(enemy_signal.pid, SIGUSR2);
    return (0);
}

void send_win_signal(int win, int player_state)
{
    if (player_state == 1)
        pause();
    if (win) {
        usleep(500);
        kill(enemy_signal.pid, SIGUSR1);
    } else {
        usleep(500);
        kill(enemy_signal.pid, SIGUSR2);
    }
    if (player_state == 2)
        pause();
}

void reset_signal(void)
{
    enemy_signal.nb_usr2 = 0;
    enemy_signal.nb_usr1 = 0;
}
