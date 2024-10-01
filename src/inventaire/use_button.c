/*
** EPITECH PROJECT, 2024
** use button
** File description:
** use button
*/

#include "inv.h"
#include "player.h"

button_t *init_use_button(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->pos = (sfVector2f){0, 0};
    button->size = (sfVector2f){22, 10};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = my_strdup("use button");
    button->rect = sfRectangleShape_create();
    button->state = 0;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    sfRectangleShape_setOutlineThickness(button->rect, 1.2);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

void update_use_button(all_menus_t *menus, player_t *player)
{
    place_button(menus, menus->inventory->
        use_button, 10, 11);
}

void display_use_button(all_menus_t *menus, video_t *video)
{
    sfRenderWindow_drawRectangleShape(video->win,
        menus->inventory->use_button->rect, NULL);
}

static void weapon_case(items_t *tmp, inv_t *inv, player_t *player)
{
    if (strcmp(tmp->name, "gourdin") == 0) {
        if (inv->hand_stuff->str_texture != NULL) {
            player->stat->attack -= my_getnbr(get_item_value("sword",
            "ATTACK"));
        }
        inv->hand_stuff->str_texture = stuff_path[GOURDIN];
        inv->hand_equiped = 0;
    }
    if (strcmp(tmp->name, "sword") == 0) {
        if (inv->hand_stuff->str_texture != NULL) {
            player->stat->attack -= my_getnbr(get_item_value("gourdin",
            "ATTACK"));
        }
        inv->hand_stuff->str_texture = stuff_path[SWORD];
        inv->hand_equiped = 0;
    }
}

static void put_stuff_on(items_t *tmp, inv_t *inv, player_t *player)
{
    if (strcmp(tmp->class, "helmet") == 0){
        player->armor[0] = 1;
        inv->helmet_stuff->str_texture = stuff_path[HELMET];
    }
    if (strcmp(tmp->class, "chest") == 0){
        player->armor[1] = 1;
        inv->chest_stuff->str_texture = stuff_path[CHESTPLATE];
    }
    if (strcmp(tmp->class, "foot") == 0){
        player->armor[2] = 1;
        inv->foot_stuff->str_texture = stuff_path[FOOT];
    }
    weapon_case(tmp, inv, player);
    put_armor_sprite_player(player);
}

static void remove_if_consumable(items_t *tmp, all_menus_t *menus,
    player_t *player)
{
    if (strcmp(tmp->class, "heal") == 0) {
        delete_item(&player->items, tmp->id, menus, player);
    }
}

static void apply_use_button(player_t *player, all_menus_t *menus)
{
    for (items_t *tmp = player->items; tmp != NULL; tmp = tmp->next) {
        if (tmp->rect_visible == 1 && tmp->equiped == 0) {
            tmp->equiped = 1;
            player->stat->attack += tmp->stat->attack;
            player->stat->defense += tmp->stat->defense;
            player->stat->speed += tmp->stat->speed;
            player->stat->health += tmp->stat->health;
            player->stat->max_health += tmp->stat->max_health;
            put_stuff_on(tmp, menus->inventory, player);
            remove_if_consumable(tmp, menus, player);
        }
    }
}

void handle_hover_use_button(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event)
{
    static sfColor color = {255, 206, 130, 255};

    if (is_hover(menus->inventory->use_button->rect,
        &event.mouseMove, video, player) == sfTrue) {
        sfRectangleShape_setOutlineColor(menus->inventory->
            use_button->rect, color);
    } else {
        sfRectangleShape_setOutlineColor(menus->inventory->
            use_button->rect, sfTransparent);
    }
}

void handle_click_use_button(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event)
{
    static sfColor color = {0, 0, 0, 100};

    if (menus->inventory->state == 2 && is_clicked(menus->inventory->use_button
        ->rect, &event.mouseButton, video, player) == sfTrue) {
        sfRectangleShape_setFillColor(menus->inventory->
            use_button->rect, color);
        apply_use_button(player, menus);
    } else {
        sfRectangleShape_setFillColor(menus->inventory->
            use_button->rect, sfTransparent);
    }
    if (menus->inventory->state == 2 && event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEnter)
        apply_use_button(player, menus);
}
