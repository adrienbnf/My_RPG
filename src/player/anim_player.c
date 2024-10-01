/*
** EPITECH PROJECT, 2024
** Anim_player
** File description:
** anim_player
*/

#include "player.h"

void hurt_animation_player(player_t *player, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - player->t_anim > 0.15){
        player->cursor_sprite.left += WIDTH_ENNEMY;
        player->t_anim = seconds;
    }
    if (player->cursor_sprite.left >= MAX_PLAYER_HURT)
        player->is_hurt = 0;
    sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
}

void attack_animation_player(player_t *player, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    player->cursor_sprite.top = OFFSET_ANIM_PLAYER * 2 * (player->looking_at);
    if (seconds - player->t_anim > 0.15){
        player->cursor_sprite.left += OFFSET_ANIM_PLAYER;
        if (player->cursor_sprite.left == ACTIVE_ATTACK_FRAME) {
            sfMusic_play(player->sword_attack);
            player->atk_active = 1;
        } else
            player->atk_active = 0;
        player->t_anim = seconds;
    }
    if (player->cursor_sprite.left >= MAX_PLAYER_ATK)
        player->is_attacking = 0;
    sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
}

void move_animation_player(player_t *player, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    player->cursor_sprite.top = OFFSET_ANIM_PLAYER * 2 * (player->looking_at);
    if (seconds - player->t_anim > 0.2){
        player->cursor_sprite.left += OFFSET_ANIM_PLAYER;
        player->t_anim = seconds;
    }
    if (player->cursor_sprite.left >= MAX_PLAYER_MOVE)
        player->cursor_sprite.left = MIN_PLAYER_MOVE;
    sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
}

void idle_animation_player(player_t *player, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - player->t_anim > 0.3){
        player->cursor_sprite.left += OFFSET_ANIM_PLAYER;
        player->t_anim = seconds;
    }
    if (player->cursor_sprite.left >= MAX_PLAYER_IDLE)
        player->cursor_sprite.left = MIN_PLAYER_IDLE;
    sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
}

void animate_player(player_t *player, sfVector2f dir, sfClock *clock)
{
    if (player->is_hurt)
        return hurt_animation_player(player, clock);
    if (player->is_attacking)
        return attack_animation_player(player, clock);
    if (dir.x == 0 && dir.y == 0)
        return idle_animation_player(player, clock);
    else
        return move_animation_player(player, clock);
}
