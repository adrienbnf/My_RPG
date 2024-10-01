/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** pnj
*/

#ifndef CHEST_H_
    #define CHEST_H_
    #define WIDTH_CHEST 32
    #define HEIGHT_CHEST 32
    #define MIN_CHEST_IDLE 128
    #define MAX_CHEST_IDLE 256
    #include "rpg.h"

typedef struct chest_s {
    sfMusic *chest;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfRectangleShape *hit_box;
    sfRectangleShape *vision;
    sfIntRect cursor_sprite;
    double t_anim;
    int opening;
    int opened;
    char *obj_name;
    struct chest_s *next;
} chest_t;

#endif /*!PNJ_H_*/
