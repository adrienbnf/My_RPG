/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** chest
*/

#include "chest.h"
#include "inv.h"

void animate_chest(chest_t *chest, sfClock *clock, player_t *player)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - chest->t_anim > 0.3){
        chest->cursor_sprite.top += HEIGHT_CHEST;
        sfMusic_play(chest->chest);
        chest->t_anim = seconds;
    }
    if (chest->cursor_sprite.top + HEIGHT_CHEST >= MAX_CHEST_IDLE){
        add_item(&player->items, chest->obj_name, len_items(player->items));
        chest->opened = 1;
    }
    sfSprite_setTextureRect(chest->sprite, chest->cursor_sprite);
}

void loop_chest(chest_t *chest, player_t *player, video_t *video)
{
    chest_t *tmp = chest;

    while (tmp != NULL){
        if (rect_are_colliding(tmp->hit_box, player->hitbox) && !tmp->opened)
            tmp->opening = 1;
        if (tmp->opening && !tmp->opened)
            animate_chest(tmp, video->clock, player);
        tmp = tmp->next;
    }
}
