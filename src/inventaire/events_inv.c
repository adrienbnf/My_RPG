/*
** EPITECH PROJECT, 2024
** events
** File description:
** contains func about events
*/

#include "inv.h"
#include "player.h"
#include "rpg.h"
#include "event.h"

sfBool is_clicked(sfRectangleShape *rect_but, sfMouseButtonEvent *event,
    video_t *video, player_t *player)
{
    sfFloatRect button_bound = sfRectangleShape_getGlobalBounds(rect_but);
    sfVector2f mouse_coord = sfRenderWindow_mapPixelToCoords(video->win,
        (sfVector2i){event->x, event->y}, player->view);

    if (event->type == sfEvtMouseButtonPressed &&
    sfFloatRect_contains(&button_bound, mouse_coord.x, mouse_coord.y)) {
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_hover(sfRectangleShape *rect_but, sfMouseMoveEvent *event,
    video_t *video, player_t *player)
{
    sfFloatRect button_bound = sfRectangleShape_getGlobalBounds(rect_but);
    sfVector2f mouse_coord = sfRenderWindow_mapPixelToCoords(video->win,
        (sfVector2i){event->x, event->y}, player->view);

    if (event->type != sfEvtMouseButtonPressed &&
    sfFloatRect_contains(&button_bound, mouse_coord.x, mouse_coord.y)) {
        return sfTrue;
    }
    return sfFalse;
}

static void down_item(player_t *player)
{
    items_t *tmp = player->items;

    while (tmp != NULL) {
        if (tmp->rect_visible == 1 && tmp->next != NULL) {
            tmp->rect_visible = 0;
            tmp = tmp->next;
            tmp->rect_visible = 1;
            break;
        }
        tmp = tmp->next;
    }
}

static void up_item(player_t *player)
{
    items_t *tmp = player->items;

    while (tmp != NULL) {
        if (tmp->rect_visible == 1 && tmp->prev != NULL) {
            tmp->rect_visible = 0;
            tmp = tmp->prev;
            tmp->rect_visible = 1;
            break;
        }
        tmp = tmp->next;
    }
}

static void move_item_rect(player_t *player, sfEvent event, all_menus_t *menus)
{
    if (menus->inventory->state == 2) {
        if (event.type == sfEvtKeyPressed & event.key.code == sfKeyDown)
            down_item(player);
        if (event.type == sfEvtKeyPressed & event.key.code == sfKeyUp)
            up_item(player);
    }
}

static void content_next_page(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event)
{
    if (is_clicked(menus->inventory->button1->rect,
        &event.mouseButton, video, player) == sfTrue) {
        if (menus->inventory->state != 0)
            menus->inventory->state = 1;
    }
    if (is_clicked(menus->inventory->button2->rect,
        &event.mouseButton, video, player) == sfTrue) {
        if (menus->inventory->state != 0)
            menus->inventory->state = 2;
    }
    if (is_clicked(menus->inventory->button3->rect,
        &event.mouseButton, video, player) == sfTrue) {
        if (menus->inventory->state != 0)
            menus->inventory->state = 3;
    }
}

static void handle_hover_pm_buttons(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event)
{
    static sfColor color = {255, 206, 130, 255};

    for (int i = 0; menus->inventory->plus_minus_buttons[i]; i++) {
        if (is_hover(menus->inventory->plus_minus_buttons[i]->rect,
            &event.mouseMove, video, player) == sfTrue) {
            sfRectangleShape_setOutlineColor(menus->inventory->
                plus_minus_buttons[i]->rect, color);
        } else {
            sfRectangleShape_setOutlineColor(menus->inventory->
                plus_minus_buttons[i]->rect, sfTransparent);
        }
    }
}

static void handle_click_pm_buttons(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event)
{
    static sfColor color = {0, 0, 0, 100};

    for (int i = 0; menus->inventory->plus_minus_buttons[i]; i++) {
        if (menus->inventory->state == 3 && is_clicked(menus->inventory->
            plus_minus_buttons[i]->rect, &event.mouseButton, video,
                player) == sfTrue) {
            sfRectangleShape_setFillColor(menus->inventory->
            plus_minus_buttons[i]->rect, color);
            modify_stat(menus, player, i);
        } else {
            sfRectangleShape_setFillColor(menus->inventory->
                plus_minus_buttons[i]->rect, sfTransparent);
        }
    }
}

void events_inv(video_t *video, sfEvent event, all_menus_t *menus,
    player_t *player)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE) {
        if (menus->inventory->state == 0)
            menus->inventory->state = 1;
        else
            menus->inventory->state = 0;
    }
    content_next_page(menus, video, player, event);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        if (menus->inventory->state != 0)
            menus->inventory->state = 0;
    }
    handle_hover_pm_buttons(menus, video, player, event);
    handle_click_pm_buttons(menus, video, player, event);
    handle_hover_use_button(menus, video, player, event);
    handle_click_use_button(menus, video, player, event);
    handle_click_sup_button(menus, video, player, event);
    handle_hover_sup_button(menus, video, player, event);
    move_item_rect(player, event, menus);
}
