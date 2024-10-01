/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** attack_player
*/

#include "player.h"

static void set_player_atk_size(player_t *player)
{
    int x = 0;
    int y = 0;

    if (player->looking_at == 0 || player->looking_at == 2){
        x = 16;
        y = 4;
    }
    if (player->looking_at == 1 || player->looking_at == 3){
        x = 4;
        y = 16;
    }
    sfRectangleShape_setSize(player->atk_hitbox, (sfVector2f){x, y});
}

static void set_player_atk_position(player_t *player)
{
    int x = player->pos.x;
    int y = player->pos.y;

    if (player->looking_at == 0)
        y += HEIGHT_PLAYER * 0.5;
    if (player->looking_at == 1)
        x += HEIGHT_PLAYER * 0.5;
    if (player->looking_at == 2)
        y -= HEIGHT_PLAYER * 0.125;
    if (player->looking_at == 3)
        x -= HEIGHT_PLAYER * 0.125;
    sfRectangleShape_setPosition(player->atk_hitbox, (sfVector2f){x, y});
}

void handle_attack(player_t *player)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft)
        || sfKeyboard_isKeyPressed(sfKeyJ)) && player->is_attacking == 0){
        player->cursor_sprite.left = MIN_PLAYER_ATK;
        player->is_attacking = 1;
    }
    if (player->is_attacking){
        set_player_atk_position(player);
        set_player_atk_size(player);
    } else
        sfRectangleShape_setOutlineThickness(player->atk_hitbox, 0.0);
}
