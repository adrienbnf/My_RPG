/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** ennemy
*/

#include "ennemy.h"
#include "player.h"
#include "path_assets.h"


void knock_back_ennemy(ennemy_t *ennemy, player_t *player, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    double delta_t = seconds - ennemy->t_move;
    int direction_kb = 0;
    sfVector2f future_pos = ennemy->pos;

    if (ennemy->kb_vector.y == VERTICAL_KB)
        future_pos.y += KB_POWER * (delta_t) * (ennemy->kb_vector.x);
    if (ennemy->kb_vector.y == HORIZONTAL_KB)
        future_pos.x += KB_POWER * (delta_t) * (ennemy->kb_vector.x);
    if (colision_e(player, future_pos))
        ennemy->pos = future_pos;
    ennemy->t_move = seconds;
}

static sfBool chase(ennemy_t *e, player_t *p, video_t *v)
{
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(p->hitbox);
    sfFloatRect rect2 = sfRectangleShape_getGlobalBounds(e->vision);
    double seconds = sfClock_getElapsedTime
    (v->clock).microseconds / 1000000.0;
    sfFloatRect intersection;

    if (sfFloatRect_intersects(&rect1, &rect2, &intersection)) {
        e->player_detected = 1;
        return sfTrue;
    }
    e->player_detected = 0;
    return sfFalse;
}

static void move(ennemy_t *e, player_t *p, video_t *v)
{
    if ((!chase(e, p, v)))
        return;
    move_ennemy(p, e, v->clock);
}

static void set_kb_vector(ennemy_t *ennemy, player_t *player)
{
    if (player->looking_at == 0 || player->looking_at == 2){
        ennemy->kb_vector.x = (player->looking_at == 0) ? 1 : -1;
        ennemy->kb_vector.y = VERTICAL_KB;
    }
    if (player->looking_at == 1 || player->looking_at == 3){
        ennemy->kb_vector.x = (player->looking_at == 1) ? 1 : -1;
        ennemy->kb_vector.y = HORIZONTAL_KB;
    }
}

static void check_attack_player(ennemy_t *ennemy, player_t *player,
    sfClock *clock)
{
    int damage = 0;
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - ennemy->t_immune >= 0.5)
        ennemy->hurt = 0;
    if (player->atk_active && !ennemy->hurt &&
        rect_are_colliding(ennemy->hit_box, player->atk_hitbox)){
            ennemy->hurt = 1;
            sfMusic_play(ennemy->damage);
            damage = player->stat->attack - ennemy->stat->defense;
            ennemy->stat->health -= (damage < 0) ? 0 : damage;
            ennemy->t_immune = seconds;
            set_kb_vector(ennemy, player);
    }
}

static void check_dead_ennemies(ennemy_t **ennemy, player_t *player)
{
    ennemy_t *prev = NULL;
    ennemy_t *tmp = *ennemy;
    int pass = 0;

    while (tmp != NULL){
        if (tmp->stat->health <= 0 && prev == NULL){
            player->xp->xp += tmp->amount_xp;
            *ennemy = tmp->next;
            pass = 1;
        }
        if (tmp->stat->health <= 0 && prev != NULL && !pass){
            player->xp->xp += tmp->amount_xp;
            prev->next = tmp->next;
            pass = 1;
        }
        pass = 0;
        prev = tmp;
        tmp = tmp->next;
    }
}

void loop_ennemy(video_t *video, ennemy_t **ennemy, player_t *p)
{
    ennemy_t *tmp = *ennemy;

    while (tmp) {
        set_looking_at(tmp, p);
        if (tmp->hurt)
            knock_back_ennemy(tmp, p, video->clock);
        else
            move(tmp, p, video);
        check_attack_player(tmp, p, video->clock);
        animate_ennemy(tmp, video->clock);
        sfRectangleShape_setPosition(tmp->hit_box,
        (sfVector2f){tmp->pos.x + 8, tmp->pos.y + 8});
        sfRectangleShape_setPosition(tmp->vision,
        (sfVector2f){tmp->pos.x- 44, tmp->pos.y - 45});
        tmp = tmp->next;
    }
    check_dead_ennemies(ennemy, p);
}
