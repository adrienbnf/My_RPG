/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** hud_player
*/

#include "player.h"
#include "inv.h"

void draw_hud_on_window(hud_t *hud, video_t *video)
{
    sfRenderWindow_drawSprite(video->win, hud->sprite, NULL);
    sfRenderWindow_drawRectangleShape(video->win, hud->xp, NULL);
    sfRenderWindow_drawRectangleShape(video->win, hud->health, NULL);
    sfRenderWindow_drawText(video->win, hud->level, NULL);
}

void display_hud_player(player_t *p, video_t *video)
{
    hud_t *hud = p->hud;
    sfVector2f size_hp = {39.4 *
    ((float)p->stat->health / (float)p->stat->max_health), 4.8};
    sfVector2f size_xp = {30 *
    ((float)p->xp->xp / (float)p->xp->target_xp), 2.8};

    hud->pos.y = sfRectangleShape_getPosition(p->vision).y + HEIGHT_VIEW - 20;
    hud->pos.x = sfRectangleShape_getPosition(p->vision).x + 20;
    sfSprite_setPosition(hud->sprite, hud->pos);
    sfRectangleShape_setPosition(hud->xp,
    (sfVector2f){hud->pos.x + 24.2, hud->pos.y + 10.8});
    sfRectangleShape_setPosition(hud->health,
    (sfVector2f){hud->pos.x + 24.2, hud->pos.y + 14.3});
    sfText_setPosition(hud->level,
    (sfVector2f){hud->pos.x + 9.5, hud->pos.y + 4});
    sfText_setString(hud->level, int_to_str(p->xp->level));
    sfRectangleShape_setSize(hud->xp, size_xp);
    sfRectangleShape_setSize(hud->health, size_hp);
    draw_hud_on_window(hud, video);
}
