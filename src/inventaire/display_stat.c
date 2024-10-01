/*
** EPITECH PROJECT, 2024
** display_stat
** File description:
** display stat
*/

#include "inv.h"
#include "player.h"
#include "rpg.h"

void update_stat(all_menus_t *menus, player_t *player)
{
    sfText_setPosition(menus->inventory->stats,
        (sfVector2f){menus->inventory->pos.x + 42,
            menus->inventory->pos.y - 15});
    sfText_setString(menus->inventory->stats, init_stat_str(player));
}

void display_stats(all_menus_t *menus, player_t *player, video_t *video)
{
    sfRenderWindow_drawText(video->win, menus->inventory->stats, NULL);
}
