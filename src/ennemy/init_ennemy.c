/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** init_ennemy
*/

#include "ennemy.h"

void assign_infos_ennemy(ennemy_t *ennemy, char *infos)
{
    char **data = my_str_to_word_array(infos, ";");

    ennemy->pos.x = my_getnbr(data[0]);
    ennemy->pos.y = my_getnbr(data[1]);
    ennemy->stat = malloc(sizeof(stat_t));
    ennemy->stat->attack = my_getnbr(data[2]);
    ennemy->stat->defense = my_getnbr(data[3]);
    ennemy->stat->health = my_getnbr(data[4]);
    ennemy->stat->speed = my_getnbr(data[5]);
    ennemy->amount_xp = my_getnbr(data[6]);
    ennemy->damage = sfMusic_createFromFile("./assets/music/damage.ogg");
}

void init_delta_t_ennemy(ennemy_t *ennemy)
{
    ennemy->t_move = 0.0;
    ennemy->t_anim = 0.0;
    ennemy->t_immune = 0.0;
}
