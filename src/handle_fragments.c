/*
** EPITECH PROJECT, 2024
** handle fragments
** File description:
** handle_fragments
*/

#include "rpg.h"
#include "player.h"
#include "inv.h"

void apply_colors(video_t *video)
{
    sfShader_setBoolUniform(video->shader, "isGray", video->isGray);
    sfShader_setBoolUniform(video->shader, "restoreSomeColor",
        video->restoreSomeColor);
    sfShader_setBoolUniform(video->shader, "restoreMoreColor",
        video->restoreMoreColor);
    sfShader_setBoolUniform(video->shader, "restoreFullColor",
        video->restoreFullColor);
}

static void modif_colors(video_t *video, int count)
{
    if (count == 1) {
        video->isGray = sfFalse;
        video->restoreSomeColor = sfTrue;
        video->restoreMoreColor = sfFalse;
        video->restoreFullColor = sfFalse;
    }
    if (count == 2) {
        video->isGray = sfFalse;
        video->restoreSomeColor = sfFalse;
        video->restoreMoreColor = sfTrue;
        video->restoreFullColor = sfFalse;
    }
    if (count == 3) {
        video->isGray = sfFalse;
        video->restoreSomeColor = sfFalse;
        video->restoreMoreColor = sfFalse;
        video->restoreFullColor = sfTrue;
    }
    apply_colors(video);
}

void verif_fragments(video_t *video, player_t *player, all_menus_t *menus)
{
    int count = 0;

    for (items_t *tmp = player->items; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->class, "fragment") == 0) {
            delete_item(&player->items, tmp->id, menus, player);
            count++;
        }
    }
    player->frag_count += count;
    modif_colors(video, player->frag_count);
}
