/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** ennemy
*/

#ifndef ENNEMY_H_
    #define ENNEMY_H_
    #define WIDTH_ENNEMY 32
    #define HEIGHT_ENNEMY 32
    #define KB_POWER 55
    #define VERTICAL_KB 1
    #define HORIZONTAL_KB 2
    #define MIN_MOB_IDLE 0
    #define MAX_MOB_IDLE 64
    #define MIN_MOB_MOVE 32
    #define MAX_MOB_MOVE 160
    #define MIN_MOB_HURT 608
    #define MAX_MOB_HURT 704
    #include "rpg.h"

typedef struct ennemy_s {
    sfMusic *damage;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfRectangleShape *hit_box;
    sfRectangleShape *vision;
    sfIntRect cursor_sprite;
    int amount_xp;
    int looking_at;
    int player_detected;
    int hurt;
    double t_immune;
    double t_anim;
    double t_move;
    sfVector2i kb_vector;
    stat_t *stat;
    struct ennemy_s *next;
} ennemy_t;

void init_ennemy_sprite(ennemy_t *mob);
ennemy_t *init_mobs(void);
void animate_ennemy(ennemy_t *ennemy, sfClock *clock);
void init_delta_t_ennemy(ennemy_t *ennemy);
void assign_infos_ennemy(ennemy_t *ennemy, char *infos);
#endif /* !ENNEMY_H_ */
