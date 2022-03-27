/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-hippolyte.david
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

typedef struct ennemy {
    int pid;
    int nb_usr1;
    int nb_usr2;
} enemy_t;

int redirect_signal(void);
int connect_player(void);
int confirm_connection(char *pid);

extern enemy_t enemy_signal;
int send_signal(int nbr);
int is_valid_coord(char *coord);
int game_handler(int player_state, char **map, char **enemy_map);
void reset_signal(void);
int check_win(char **map);
int attack(char **enemy_map);
void send_win_signal(int win, int player_state);
int verify_map(char **argv, int argc);
int verify_argv(int argc, char **argv);
int game_loop(char **map, char **enemy_map, int player_state);
int display_result(int win);
#endif /* !NAVY_H_ */
