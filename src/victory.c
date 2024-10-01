/*
** EPITECH PROJECT, 2024
** victory
** File description:
** victory
*/

#include "player.h"

void init_victory(player_t *player)
{
    player->victory_sprite = sfSprite_create();
    player->victory_texture = sfTexture_createFromFile("assets/Victory.png",
        NULL);
    sfSprite_setTexture(player->victory_sprite,
        player->victory_texture, sfTrue);
    sfSprite_setOrigin(player->victory_sprite, (sfVector2f){333, 187.5});
    sfSprite_scale(player->victory_sprite, (sfVector2f){0.1, 0.1});
}

void update_and_display_victory(player_t *player, video_t *video)
{
    if (player->frag_count == 3) {
        sfSprite_setPosition(player->victory_sprite,
        (sfVector2f){(sfSprite_getPosition(player->sprite).x + 16 / 2),
            (sfSprite_getPosition(player->sprite).y + 16 / 2) - 20});
        sfRenderWindow_drawSprite(video->win, player->victory_sprite,
            NULL);
    }
}
