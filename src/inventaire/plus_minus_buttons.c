/*
** EPITECH PROJECT, 2024
** plus minus button
** File description:
** plus_minus_buttons
*/

#include "player.h"
#include "inv.h"

void place_button(all_menus_t *menus, button_t *but, int x, int y)
{
    but->pos = sfSprite_getPosition(menus->inventory->sprite);
    sfRectangleShape_setPosition(but->rect, (sfVector2f){but->pos.x - x,
        but->pos.y - y});
}

void update_plus_minus_buttons(all_menus_t *menus, player_t *player)
{
    place_button(menus, menus->inventory->
        plus_minus_buttons[ATT_PLUS], 43, 25);
    place_button(menus, menus->inventory->
        plus_minus_buttons[ATT_MINUS], 31, 25);
    place_button(menus, menus->inventory->
        plus_minus_buttons[DEF_PLUS], -18, 25);
    place_button(menus, menus->inventory->
        plus_minus_buttons[DEF_MINUS], -29, 25);
    place_button(menus, menus->inventory->
        plus_minus_buttons[SPD_PLUS], 43, -8);
    place_button(menus, menus->inventory->
        plus_minus_buttons[SPD_MINUS], 31, -8);
    place_button(menus, menus->inventory->
        plus_minus_buttons[HEAL_PLUS], -18, -8);
    place_button(menus, menus->inventory->
        plus_minus_buttons[HEAL_MINUS], -30, -8);
    place_button(menus, menus->inventory->
        plus_minus_buttons[MHEAL_PLUS], 11, -33);
    place_button(menus, menus->inventory->
        plus_minus_buttons[MHEAL_MINUS], 0, -33);
}

void display_plus_minus_buttons(all_menus_t *menus, video_t *video)
{
    for (int i = 0; menus->inventory->plus_minus_buttons[i]; i++) {
        sfRenderWindow_drawRectangleShape(video->win,
            menus->inventory->plus_minus_buttons[i]->rect, NULL);
    }
}
