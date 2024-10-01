/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** pnj
*/

#include "player.h"
#include "pnj.h"

static sfBool player_approach(pnj_t *pnj, player_t *p, video_t *v)
{
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(p->hitbox);
    sfFloatRect rect2 = sfRectangleShape_getGlobalBounds(pnj->vision);
    double seconds = sfClock_getElapsedTime
    (v->clock).microseconds / 1000000.0;
    sfFloatRect intersection;

    if (sfFloatRect_intersects(&rect1, &rect2, &intersection))
        return sfTrue;
    pnj->text_box->i = 0;
    pnj->text_box->index = 0;
    pnj->text_box->tmp = seconds;
    pnj->text_box->write = 0;
    return sfFalse;
}

void idle_pnj(pnj_t *pnj, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - pnj->t_anim > 0.3){
        pnj->cursor_sprite.left += OFFSET_ANIM_PLAYER;
        pnj->t_anim = seconds;
    }
    if (pnj->cursor_sprite.left >= MAX_PLAYER_IDLE)
        pnj->cursor_sprite.left = MIN_PLAYER_IDLE;
    sfSprite_setTextureRect(pnj->sprite, pnj->cursor_sprite);
}

static void talk(pnj_t *pnj, player_t *p, video_t *v)
{
    if ((!player_approach(pnj, p, v)))
        return;
    sfRenderWindow_drawSprite(v->win, pnj->text_box->sprite, NULL);
    sfSprite_setPosition(pnj->text_box->sprite, (sfVector2f)
    {p->pos.x - 90, p->pos.y + 20});
    sfText_setPosition(pnj->text_box->text, (sfVector2f)
    {p->pos.x - 82, p->pos.y + 37});
    print_text(pnj->text_box, v->win, v->clock);
}

void loop_pnj(pnj_t *pnj, player_t *player, video_t *video)
{
    pnj_t *tmp = pnj;

    while (tmp != NULL){
        talk(tmp, player, video);
        idle_pnj(tmp, video->clock);
        tmp = tmp->next;
    }
}
