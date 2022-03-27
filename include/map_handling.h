/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** map_handling
*/

#ifndef MAP_HANDLING_H_
    #define MAP_HANDLING_H_

void is_a_boat(int i, char *coord, char nb, char **map);
void put_in_map(char **map, char *coord, char nb);
int error_check(char *line, int i);
int update_map(char **map, char *file);
void fill_map(char **map);
char  **init_map(char *filepath);
void display_map(char **boat_map);
int abs_val(int value);
int update_own_map(char **map, char *coord);
char **init_empty_map(void);
int update_by_char(char **map, char *coord, char new_char);
int win_handler(char **map, int player_state);
#endif /* !MAP_HANDLING_H_ */
