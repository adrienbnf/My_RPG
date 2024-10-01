/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** move_ennemy
*/

#include "ennemy.h"
#include "player.h"
#include "rpg.h"

sfVector2f normalize_two(sfVector2f v)
{
    float length = sqrt(v.x * v.x + v.y * v.y);

    if (length != 0) {
        v.x /= length;
        v.y /= length;
    }
    return v;
}

static sfVector2f move(ennemy_t *e, player_t *p, float deltaTime)
{
    sfVector2f current = e->pos;
    sfVector2f target = (sfVector2f){p->pos.x - 8, p->pos.y - 8};
    float speed = e->stat->speed;
    sfVector2f direction = {target.x - current.x, target.y - current.y};
    sfVector2f n = normalize_two(direction);
    sfVector2f movement = {n.x * speed * deltaTime, n.y * speed * deltaTime};

    if (sqrt((movement.x * movement.x) + (movement.y * movement.y)) >=
        sqrt((direction.x * direction.x) + (direction.y * direction.y)))
        return target;
    return (sfVector2f){current.x + movement.x, current.y + movement.y};
}

int colision_e(player_t *p, sfVector2f r)
{
    return (p->colision->map[(int)round(r.y / 8.0)][(int)round(r.x / 8.0)]
        != '#' && p->colision->map[(int)round(r.y / 8.0) + 1]
        [(int)round(r.x / 8.0)] != '#' &&
        p->colision->map[(int)round(r.y / 8.0)]
        [(int)round(r.x / 8.0) + 1] != '#' &&
        p->colision->map[(int)round(r.y / 8.0) + 1]
        [(int)round(r.x / 8.0) + 1] != '#');
}

void move_ennemy(player_t *p, ennemy_t *e, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    float delta = seconds - e->t_move;
    sfVector2f r;

    if (seconds - e->t_move > 0.02)
        delta = 0;
    r = move(e, p, delta);
    if (colision_e(p, r))
        e->pos = r;
    sfRectangleShape_setPosition(e->hit_box,
    (sfVector2f){e->pos.x + 8, e->pos.y + 8});
    sfRectangleShape_setPosition(e->vision,
    (sfVector2f){e->pos.x- 44, e->pos.y - 45});
    e->t_move = seconds;
}
