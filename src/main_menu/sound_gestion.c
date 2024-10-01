/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** sound_gestion
*/


#include "player.h"
#include "rpg.h"
#include "my_menu.h"
#include "inv.h"


void sound_gestion(video_t *video, all_menus_t *menus, player_t *player)
{
    menus->menu->sound_bar->vol = abs(menus->menu->sound_bar->x * 100 / 68);
    sfMusic_setVolume(player->damage, menus->menu->sound_bar->vol);
    sfMusic_setVolume(player->sword_attack, menus->menu->sound_bar->vol);
    if (menus->menu->sound_bar->lock_music == sfTrue) {
        sfMusic_setVolume(video->music, 0);
        return;
    }
    if (menus->menu->sound_bar->vol >= 10)
        sfMusic_setVolume(video->music, menus->menu->sound_bar->vol - 10);
    else
        sfMusic_setVolume(video->music, 0);
}
