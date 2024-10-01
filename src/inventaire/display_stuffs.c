/*
** EPITECH PROJECT, 2024
** display stuffs
** File description:
** contains func about updating an ddisplaying the stuffs sprite
*/

#include "player.h"
#include "inv.h"
#include "rpg.h"

static void display_chest(all_menus_t *menus, video_t *video)
{
    if (menus->inventory->chest_stuff->str_texture != NULL) {
        sfRenderWindow_drawSprite(video->win,
            menus->inventory->chest_stuff->sprite, NULL);
    }
}

static void display_foot(all_menus_t *menus, video_t *video)
{
    if (menus->inventory->foot_stuff->str_texture != NULL) {
        sfRenderWindow_drawSprite(video->win,
            menus->inventory->foot_stuff->sprite, NULL);
    }
}

static void display_helmet(all_menus_t *menus, video_t *video)
{
    if (menus->inventory->helmet_stuff->str_texture != NULL) {
        sfRenderWindow_drawSprite(video->win,
            menus->inventory->helmet_stuff->sprite, NULL);
    }
}

static void display_hand(all_menus_t *menus, video_t *video)
{
    if (menus->inventory->hand_stuff->str_texture != NULL) {
        sfRenderWindow_drawSprite(video->win,
            menus->inventory->hand_stuff->sprite, NULL);
    }
}

static void update_foot_stuff(all_menus_t *menus, player_t *player)
{
    if (menus->inventory->foot_stuff->str_texture != NULL &&
        menus->inventory->foot_equiped == 0) {
        menus->inventory->foot_stuff->texture =
            sfTexture_createFromFile(menus->inventory->
                foot_stuff->str_texture, NULL);
        sfSprite_setTexture(menus->inventory->foot_stuff->sprite,
            menus->inventory->foot_stuff->texture, sfTrue);
        menus->inventory->foot_equiped = 1;
    }
    menus->inventory->foot_stuff->pos =
    sfSprite_getPosition(menus->inventory->sprite);
    sfSprite_setPosition(menus->inventory->foot_stuff->sprite,
        menus->inventory->foot_stuff->pos);
    sfRectangleShape_setPosition(menus->inventory->foot_stuff->rect,
        (sfVector2f){menus->inventory->foot_stuff->pos.x - 36,
            menus->inventory->foot_stuff->pos.y + 10});
}

static void update_hand_stuff(all_menus_t *menus, player_t *player)
{
    if (menus->inventory->hand_stuff->str_texture != NULL &&
        menus->inventory->hand_equiped == 0) {
        menus->inventory->hand_stuff->texture =
            sfTexture_createFromFile(menus->inventory->
                hand_stuff->str_texture, NULL);
        sfSprite_setTexture(menus->inventory->hand_stuff->sprite,
            menus->inventory->hand_stuff->texture, sfTrue);
        menus->inventory->hand_equiped = 1;
    }
    menus->inventory->hand_stuff->pos =
    sfSprite_getPosition(menus->inventory->sprite);
    sfSprite_setPosition(menus->inventory->hand_stuff->sprite,
        menus->inventory->hand_stuff->pos);
    sfRectangleShape_setPosition(menus->inventory->hand_stuff->rect,
        (sfVector2f){menus->inventory->hand_stuff->pos.x - 70,
            menus->inventory->hand_stuff->pos.y + 10});
}

static void update_helmet_stuff(all_menus_t *menus, player_t *player)
{
    if (menus->inventory->helmet_stuff->str_texture != NULL &&
        menus->inventory->helmet_equiped == 0) {
        menus->inventory->helmet_stuff->texture =
            sfTexture_createFromFile(menus->inventory->
                helmet_stuff->str_texture, NULL);
        sfSprite_setTexture(menus->inventory->helmet_stuff->sprite,
            menus->inventory->helmet_stuff->texture, sfTrue);
            menus->inventory->helmet_equiped = 1;
    }
    menus->inventory->helmet_stuff->pos =
    sfSprite_getPosition(menus->inventory->sprite);
    sfSprite_setPosition(menus->inventory->helmet_stuff->sprite,
        menus->inventory->helmet_stuff->pos);
    sfRectangleShape_setPosition(menus->inventory->helmet_stuff->rect,
        (sfVector2f){menus->inventory->helmet_stuff->pos.x - 58,
            menus->inventory->helmet_stuff->pos.y - 10});
}

static void update_chest_stuff(all_menus_t *menus, player_t *player)
{
    if (menus->inventory->chest_stuff->str_texture != NULL &&
        menus->inventory->chest_equiped == 0) {
        menus->inventory->chest_stuff->texture =
            sfTexture_createFromFile(menus->inventory->
                chest_stuff->str_texture, NULL);
        sfSprite_setTexture(menus->inventory->chest_stuff->sprite,
            menus->inventory->chest_stuff->texture, sfTrue);
        menus->inventory->chest_equiped = 1;
    }
        menus->inventory->chest_stuff->pos =
        sfSprite_getPosition(menus->inventory->sprite);
        sfSprite_setPosition(menus->inventory->chest_stuff->sprite,
            menus->inventory->chest_stuff->pos);
        sfRectangleShape_setPosition(menus->inventory->chest_stuff->rect,
            (sfVector2f){menus->inventory->chest_stuff->pos.x - 36,
                menus->inventory->chest_stuff->pos.y - 20});
}

void update_stuffs(all_menus_t *menus, player_t *player)
{
    update_helmet_stuff(menus, player);
    update_hand_stuff(menus, player);
    update_foot_stuff(menus, player);
    update_chest_stuff(menus, player);
    update_frag_stuff(menus, player);
}

void display_stuffs(all_menus_t *menus, player_t *player, video_t *video)
{
    display_helmet(menus, video);
    display_hand(menus, video);
    display_foot(menus, video);
    display_chest(menus, video);
    display_frag(menus, video);
}
