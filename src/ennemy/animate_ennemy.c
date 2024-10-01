/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** animate_ennemy
*/

#include "ennemy.h"

void hurt_animation_ennemy(ennemy_t *ennemy, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    ennemy->cursor_sprite.top = WIDTH_ENNEMY * 2 * (ennemy->looking_at);
    if (seconds - ennemy->t_anim > 0.15){
        ennemy->cursor_sprite.left += WIDTH_ENNEMY;
        ennemy->t_anim = seconds;
    }
    if (ennemy->cursor_sprite.left >= MAX_MOB_HURT
        || ennemy->cursor_sprite.left < MIN_MOB_HURT)
        ennemy->cursor_sprite.left = MIN_MOB_HURT;
    sfSprite_setTextureRect(ennemy->sprite, ennemy->cursor_sprite);
}

void move_animation_ennemy(ennemy_t *ennemy, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    ennemy->cursor_sprite.top = WIDTH_ENNEMY * 2 * (ennemy->looking_at);
    if (seconds - ennemy->t_anim > 0.2){
        ennemy->cursor_sprite.left += WIDTH_ENNEMY;
        ennemy->t_anim = seconds;
    }
    if (ennemy->cursor_sprite.left >= MAX_MOB_MOVE
        || ennemy->cursor_sprite.left < MIN_MOB_MOVE)
        ennemy->cursor_sprite.left = MIN_MOB_MOVE;
    sfSprite_setTextureRect(ennemy->sprite, ennemy->cursor_sprite);
}

void idle_animation_ennemy(ennemy_t *ennemy, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - ennemy->t_anim > 0.3){
        ennemy->cursor_sprite.left += WIDTH_ENNEMY;
        ennemy->t_anim = seconds;
    }
    if (ennemy->cursor_sprite.left >= MAX_MOB_IDLE)
        ennemy->cursor_sprite.left = MIN_MOB_IDLE;
    sfSprite_setTextureRect(ennemy->sprite, ennemy->cursor_sprite);
}

void animate_ennemy(ennemy_t *ennemy, sfClock *clock)
{
    if (ennemy->hurt)
        return hurt_animation_ennemy(ennemy, clock);
    if (!ennemy->player_detected)
        return idle_animation_ennemy(ennemy, clock);
    else
        return move_animation_ennemy(ennemy, clock);
}
