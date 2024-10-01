/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** Header that contains the paths of the assets
*/

#ifndef COL_H_
    #define COL_H_
    #include <sys/stat.h>
    #include "player.h"

int get_x(char **tab);
int get_y(char **tab);
player_t *init_colision(player_t *player, char const *path);
int arrows_input(player_t *p, int key);
#endif /* !PATH_H_ */
