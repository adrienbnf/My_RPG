/*
** EPITECH PROJECT, 2023
** arrow mov
** File description:
** ..
*/

#include "player.h"


char **arraycpy(char **src, char **dest)
{
    int i = 0;

    if (src == NULL || dest == NULL)
        return NULL;
    for (; src[i]; i++) {
        strcpy(dest[i], src[i]);
    }
    dest[i] = NULL;
    return dest;
}

static int arrow_up(player_t *p)
{
    sfVector2i pi;

    pi.x = (int)p->colision->pos_player.x;
    pi.y = (int)p->colision->pos_player.y;
    if (p->colision->map[pi.y - 1][pi.x] != '#' &&
    p->colision->map[pi.y - 1][pi.x + 1] != '#') {
        p->colision->map = arraycpy(p->colision->map_copy, p->colision->map);
        p->colision->map[pi.y - 1][pi.x] = 'P';
        p->colision->pos_player.y = round(p->pos.y / 8);
        return 1;
    }
    if ((p->pos.y / 8.00) + 0.2 > (float)(pi.y))
        return 1;
    return 0;
}

static int arrow_down(player_t *p)
{
    sfVector2i pi;

    pi.x = (int)p->colision->pos_player.x;
    pi.y = (int)p->colision->pos_player.y;
    if (p->colision->map[pi.y + 1][pi.x] != '#' &&
    p->colision->map[pi.y + 1][pi.x + 1] != '#' &&
    p->colision->map[pi.y + 2][pi.x] != '#' &&
    p->colision->map[pi.y + 2][pi.x + 1] != '#') {
        p->colision->map = arraycpy(p->colision->map_copy, p->colision->map);
        p->colision->map[pi.y + 1][pi.x] = 'P';
        p->colision->pos_player.y = round(p->pos.y / 8);
        return 1;
    }
    if ((p->pos.y / 8.00) - 0.3 < (float)(pi.y))
        return 1;
    return 0;
}

static int arrow_left(player_t *p)
{
    sfVector2i pi;

    pi.x = (int)p->colision->pos_player.x;
    pi.y = (int)p->colision->pos_player.y;
    if (p->colision->map[pi.y][pi.x - 1] != '#' &&
    p->colision->map[pi.y + 1][pi.x - 1] != '#') {
        p->colision->map = arraycpy(p->colision->map_copy, p->colision->map);
        p->colision->map[pi.y][pi.x - 1] = 'P';
        p->colision->pos_player.x = round(p->pos.x / 8);
        return 1;
    }
    if ((p->pos.x / 8.00) > (float)(pi.x - 0.5))
        return 1;
    return 0;
}

static int arrow_right(player_t *p)
{
    sfVector2i pi;

    pi.x = (int)p->colision->pos_player.x;
    pi.y = (int)p->colision->pos_player.y;
    if (p->colision->map[pi.y][pi.x + 1] != '#' &&
    p->colision->map[pi.y + 1][pi.x + 1] != '#' &&
    p->colision->map[pi.y][pi.x + 2] != '#' &&
    p->colision->map[pi.y + 1][pi.x + 2] != '#') {
        p->colision->map = arraycpy(p->colision->map_copy, p->colision->map);
        p->colision->map[pi.y][pi.x + 1] = 'P';
        p->colision->pos_player.x = round(p->pos.x / 8);
        return 1;
    }
    if ((p->pos.x / 8.00) < (float)(pi.x + 0.5))
        return 1;
    return 0;
}

int arrows_input(player_t *p, int key)
{
    if (key == UP)
        return arrow_up(p);
    if (key == DOWN)
        return arrow_down(p);
    if (key == RIGHT)
        return arrow_right(p);
    if (key == LEFT)
        return arrow_left(p);
    return 0;
}
