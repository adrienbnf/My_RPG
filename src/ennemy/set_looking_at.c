/*
** EPITECH PROJECT, 2024
** Myrpg
** File description:
** set_looking_at
*/

#include "player.h"

static float abs_float(float nbr)
{
    if (nbr < 0.0)
        return nbr * (-1.0);
    return nbr;
}

void set_looking_at(ennemy_t *mob, player_t *player)
{
    float diff1 = player->pos.x - mob->pos.x;
    float diff2 = player->pos.y - mob->pos.y;

    if (abs_float(diff1) > abs_float(diff2)){
        if (diff1 < 0.0)
            mob->looking_at = 3;
        else
            mob->looking_at = 1;
    } else {
        if (diff2 < 0.0)
            mob->looking_at = 2;
        else
            mob->looking_at = 0;
    }
}
