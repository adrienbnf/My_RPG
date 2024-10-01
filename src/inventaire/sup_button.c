/*
** EPITECH PROJECT, 2024
** use button
** File description:
** use button
*/

#include "inv.h"
#include "player.h"

button_t *init_sup_button(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->pos = (sfVector2f){0, 0};
    button->size = (sfVector2f){22, 10};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = my_strdup("sup button");
    button->rect = sfRectangleShape_create();
    button->state = 0;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    sfRectangleShape_setOutlineThickness(button->rect, 1.2);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

void update_sup_button(all_menus_t *menus, player_t *player)
{
    place_button(menus, menus->inventory->
        sup_button, 10, -6);
}

void display_sup_button(all_menus_t *menus, video_t *video)
{
    sfRenderWindow_drawRectangleShape(video->win,
        menus->inventory->sup_button->rect, NULL);
}

void handle_hover_sup_button(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event)
{
    static sfColor color = {255, 206, 130, 255};

    if (is_hover(menus->inventory->sup_button->rect,
        &event.mouseMove, video, player) == sfTrue) {
        sfRectangleShape_setOutlineColor(menus->inventory->
            sup_button->rect, color);
    } else {
        sfRectangleShape_setOutlineColor(menus->inventory->
            sup_button->rect, sfTransparent);
    }
}

static int get_current_item(items_t *item)
{
    items_t *tmp = item;

    while (tmp != NULL) {
        if (tmp->rect_visible == 1)
            return tmp->id;
        tmp = tmp->next;
    }
}

void handle_click_sup_button(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event)
{
    static sfColor color = {0, 0, 0, 100};

    if (menus->inventory->state == 2 && is_clicked(menus->inventory->
        sup_button->rect, &event.mouseButton, video, player) == sfTrue) {
        sfRectangleShape_setFillColor(menus->inventory->
            sup_button->rect, color);
            printf("delete\n");
            delete_item(&player->items, get_current_item(player->items),
                menus, player);
    } else {
        sfRectangleShape_setFillColor(menus->inventory->
            sup_button->rect, sfTransparent);
    }
    if (menus->inventory->state == 2 && event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyBackspace)
        delete_item(&player->items, get_current_item(player->items), menus,
            player);
}
