/*
** EPITECH PROJECT, 2024
** modif stat
** File description:
** modif stat
*/

#include "path_assets.h"
#include "rpg.h"
#include "inv.h"
#include "player.h"

char *init_modif_stat_str(player_t *player)
{
    char *str = my_strcat("attack: ", int_to_str(player->stat->attack));

    str = my_strcat(str, "                   defense: ");
    str = my_strcat(str, int_to_str(player->stat->defense));
    str = my_strcat(str, "\n\n\n\n\n speed: ");
    str = my_strcat(str, int_to_str(player->stat->speed));
    str = my_strcat(str, "                     health: ");
    str = my_strcat(str, int_to_str(player->stat->health));
    str = my_strcat(str, "\n\n\n\n               max health: ");
    str = my_strcat(str, int_to_str(player->stat->max_health));
    str = my_strcat(str, "\n\n               "
    "                              credit(s): ");
    str = my_strcat(str, int_to_str(player->xp->credit));
    return str;
}

sfText *init_modif_stat(player_t *player)
{
    sfFont* font = sfFont_createFromFile(path_assets[FONT]);
    sfText* text = sfText_create();
    sfColor color = {92, 64, 51, 255};

    sfText_setString(text, init_modif_stat_str(player));
    sfText_setFont(text, font);
    sfText_setScale(text, (sfVector2f){0.20, 0.20});
    sfText_setColor(text, color);
    sfText_setPosition(text, (sfVector2f){0, 0});
    return text;
}

void update_modif_stat(all_menus_t *menus, player_t *player)
{
    sfText_setPosition(menus->inventory->modif_stat,
        (sfVector2f){menus->inventory->pos.x - 38,
            menus->inventory->pos.y - 27});
    sfText_setString(menus->inventory->modif_stat,
        init_modif_stat_str(player));
    if (player->stat->health > player->stat->max_health)
        player->stat->health = player->stat->max_health;
}

void display_modif_stat(all_menus_t *menus, player_t *player, video_t *video)
{
    sfRenderWindow_drawText(video->win, menus->inventory->modif_stat, NULL);
}
