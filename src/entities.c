/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** entities
*/

#include "player.h"
#include "entities.h"

void entities_loop(entities_t *entities, video_t *video, player_t *player)
{
    loop_ennemy(video, &entities->ennemies, player);
    loop_pnj(entities->pnj, player, video);
    loop_chest(entities->chest, player, video);
}
