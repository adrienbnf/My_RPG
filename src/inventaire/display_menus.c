/*
** EPITECH PROJECT, 2024
** display
** File description:
** contains func about displaying things
*/

#include "player.h"
#include "inv.h"
#include "rpg.h"

static void place_button1(all_menus_t *menus, player_t *player)
{
    menus->inventory->button1->pos =
    sfSprite_getPosition(menus->inventory->sprite);
    sfRectangleShape_setPosition(menus->inventory->button1->rect,
        (sfVector2f){menus->inventory->button1->pos.x - 72,
            menus->inventory->button1->pos.y - 58});
}

static void place_button2(all_menus_t *menus, player_t *player)
{
    menus->inventory->button2->pos =
    sfSprite_getPosition(menus->inventory->sprite);
    sfRectangleShape_setPosition(menus->inventory->button2->rect,
        (sfVector2f){menus->inventory->button2->pos.x - 42,
            menus->inventory->button3->pos.y - 58});
}

static void place_button3(all_menus_t *menus, player_t *player)
{
    menus->inventory->button3->pos =
    sfSprite_getPosition(menus->inventory->sprite);
    sfRectangleShape_setPosition(menus->inventory->button3->rect,
        (sfVector2f){menus->inventory->button3->pos.x - 10,
            menus->inventory->button3->pos.y - 58});
}

void place_page_button(all_menus_t *menus, player_t *player)
{
    place_button1(menus, player);
    place_button2(menus, player);
    place_button3(menus, player);
}

void place_background(all_menus_t *menus, player_t *player)
{
    menus->inventory->pos = sfSprite_getPosition(player->sprite);
    sfSprite_setPosition(menus->inventory->sprite,
        (sfVector2f){menus->inventory->pos.x + 16 / 2,
            menus->inventory->pos.y + 16 / 2});
    sfSprite_setPosition(menus->inventory->sprite2,
        (sfVector2f){menus->inventory->pos.x + 16 / 2,
            menus->inventory->pos.y + 16 / 2});
    sfSprite_setPosition(menus->inventory->sprite3,
        (sfVector2f){menus->inventory->pos.x + 16 / 2,
            menus->inventory->pos.y + 16 / 2});
    sfText_setPosition(menus->inventory->stats, menus->inventory->pos);
}

static void upt_inv(all_menus_t *menus, player_t *player)
{
    place_background(menus, player);
    place_page_button(menus, player);
    update_stuffs(menus, player);
    update_stat(menus, player);
    update_item_list(menus, player);
    update_item_description(menus, player);
    update_modif_stat(menus, player);
    update_plus_minus_buttons(menus, player);
    update_use_button(menus, player);
    update_sup_button(menus, player);
}

void display_inv(all_menus_t *menus, player_t *player, video_t *video)
{
    upt_inv(menus, player);
    if (menus->inventory->state == 1) {
        sfRenderWindow_drawSprite(video->win, menus->inventory->sprite,
            NULL);
        display_stuffs(menus, player, video);
        display_stats(menus, player, video);
    } else if (menus->inventory->state == 2) {
        sfRenderWindow_drawSprite(video->win, menus->inventory->sprite2,
            NULL);
        display_items_name(menus, player, video);
        display_items_description(menus, player, video);
        display_use_button(menus, video);
        display_sup_button(menus, video);
    }
    if (menus->inventory->state == 3) {
        sfRenderWindow_drawSprite(video->win, menus->inventory->sprite3,
            NULL);
        display_modif_stat(menus, player, video);
        display_plus_minus_buttons(menus, video);
    }
}

void display_menus(all_menus_t *menus, player_t *player, video_t *video)
{
    display_inv(menus, player, video);
}
