/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** default_data_player
*/

#include "player.h"

stat_t *init_default_player_stat(void)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->attack = BASE_PLAYER_ATK;
    stat->defense = BASE_PLAYER_DEFENSE;
    stat->health = BASE_PLAYER_HEALTH;
    stat->speed = BASE_PLAYER_SPEED;
    stat->max_health = BASE_PLAYER_HEALTH;
    return stat;
}

xp_t *init_default_player_xp(void)
{
    xp_t *xp = malloc(sizeof(xp_t));

    xp->credit = 3;
    xp->level = 1;
    xp->target_xp = TARGET_XP_BASE;
    xp->xp = 0;
    return xp;
}
