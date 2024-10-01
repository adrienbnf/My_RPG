/*
** EPITECH PROJECT, 2024
** dspaly items
** File description:
** display items
*/

#include "player.h"
#include "inv.h"
#include "rpg.h"

void display_items_name(all_menus_t *menus, player_t *player, video_t *video)
{
    items_t *tmp = player->items;

    sfRenderWindow_drawText(video->win, menus->inventory->item_list, sfFalse);
    while (tmp != NULL) {
        if (tmp->rect_visible)
            sfRenderWindow_drawRectangleShape(video->win, tmp->rect, NULL);
        tmp = tmp->next;
    }
}

void display_items_description(all_menus_t *menus, player_t *player,
    video_t *video)
{
    sfRenderWindow_drawText(video->win, menus->inventory->item_description,
        sfFalse);
}

static void update_rect_item(player_t *player, all_menus_t *menus)
{
    items_t *tmp = player->items;

    while (tmp != NULL) {
        sfRectangleShape_setPosition(tmp->rect,
            (sfVector2f){menus->inventory->pos.x - 56,
                menus->inventory->pos.y - 19 + (tmp->id * 7 + 1.5 * tmp->id)});
        tmp = tmp->next;
    }
}

void update_item_list(all_menus_t *menus, player_t *player)
{
    sfText_setPosition(menus->inventory->item_list,
        (sfVector2f){menus->inventory->pos.x - 55,
            menus->inventory->pos.y - 28});
    update_rect_item(player, menus);
    sfText_setString(menus->inventory->item_list,
        init_item_list_str(player->items));
}

void update_item_description(all_menus_t *menus, player_t *player)
{
    sfText_setPosition(menus->inventory->item_description,
        (sfVector2f){menus->inventory->pos.x + 35,
            menus->inventory->pos.y - 20});
    sfText_setString(menus->inventory->item_description,
        init_item_description_str(player->items));
}
