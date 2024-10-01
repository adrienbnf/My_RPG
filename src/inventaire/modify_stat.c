/*
** EPITECH PROJECT, 2024
** modify stat
** File description:
** modify stat
*/

#include "player.h"
#include "inv.h"

static void third_content_modify_stat(all_menus_t *menus, player_t *player,
    int i)
{
    if (i == MHEAL_MINUS) {
        if (player->stat->max_health > 1) {
            player->stat->max_health--;
            player->xp->credit += player->stat->max_health % 2;
        }
    }
}

static void second_content_modify_stat(all_menus_t *menus, player_t *player,
    int i)
{
    if (i == HEAL_PLUS) {
        if (player->xp->credit > 0 && player->stat->health <
            player->stat->max_health) {
            player->xp->credit--;
            player->stat->health++;
        }
    }
    if (i == HEAL_MINUS) {
        if (player->stat->health > 1) {
            player->stat->health--;
            player->xp->credit += player->stat->health % 2;
        }
    }
    if (i == MHEAL_PLUS) {
        if (player->xp->credit > 0) {
            player->xp->credit--;
            player->stat->max_health++;
        }
    }
    third_content_modify_stat(menus, player, i);
}

static void content_modify_stat(all_menus_t *menus, player_t *player, int i)
{
    if (i == DEF_MINUS) {
        if (player->stat->defense > 1) {
            player->stat->defense--;
            player->xp->credit++;
        }
    }
    if (i == SPD_PLUS) {
        if (player->xp->credit > 0) {
            player->xp->credit--;
            player->stat->speed++;
        }
    }
    if (i == SPD_MINUS) {
        if (player->stat->speed > 1) {
            player->stat->speed--;
            player->xp->credit++;
        }
    }
    second_content_modify_stat(menus, player, i);
}

void modify_stat(all_menus_t *menus, player_t *player, int i)
{
    if (i == ATT_PLUS) {
        if (player->xp->credit > 0) {
            player->xp->credit--;
            player->stat->attack++;
        }
    }
    if (i == ATT_MINUS) {
        if (player->stat->attack > 1) {
            player->stat->attack--;
            player->xp->credit++;
        }
    }
    if (i == DEF_PLUS) {
        if (player->xp->credit > 0) {
            player->xp->credit--;
            player->stat->defense++;
        }
    }
    content_modify_stat(menus, player, i);
}
