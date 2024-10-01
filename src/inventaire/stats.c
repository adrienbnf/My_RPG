/*
** EPITECH PROJECT, 2024
** init_stat
** File description:
** i
*/

#include "path_assets.h"
#include "inv.h"
#include "player.h"
#include "rpg.h"

char *init_stat_str(player_t *player)
{
    char *str = my_strcat("attack: ", int_to_str(player->stat->attack));

    str = my_strcat(str, "\n\ndefense: ");
    str = my_strcat(str, int_to_str(player->stat->defense));
    str = my_strcat(str, "\n\nspeed: ");
    str = my_strcat(str, int_to_str(player->stat->speed));
    str = my_strcat(str, "\n\nhealth: ");
    str = my_strcat(str, int_to_str(player->stat->health));
    str = my_strcat(str, "\n\nmax health: ");
    str = my_strcat(str, int_to_str(player->stat->max_health));
    return str;
}

sfText *init_stats(player_t *player)
{
    sfFont* font = sfFont_createFromFile(path_assets[FONT]);
    sfText* text = sfText_create();
    sfColor color = {92, 64, 51, 255};

    sfText_setString(text, init_stat_str(player));
    sfText_setFont(text, font);
    sfText_setScale(text, (sfVector2f){0.15, 0.15});
    sfText_setColor(text, color);
    sfText_setPosition(text, (sfVector2f){0, 0});
    return text;
}
