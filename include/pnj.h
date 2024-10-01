/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** pnj
*/

#ifndef PNJ_H_
    #define PNJ_H_
    #define WIDTH_PNJ 32
    #define HEIGHT_PNJ 32
    #define MIN_PNJ_IDLE 0
    #define MAX_PNJ_IDLE 64
    #define MIN_PLAYER_IDLE 0
    #define MAX_PLAYER_IDLE 64
    #include "rpg.h"


typedef struct text_box_s {
    sfClock *clock;
    sfFont *font;
    int i;
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    int write;
    int index;
    double tmp;
    sfVector2f pos;
    char **comment;
}text_box_t;

typedef struct pnj_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfRectangleShape *hit_box;
    sfRectangleShape *vision;
    sfIntRect cursor_sprite;
    text_box_t *text_box;
    double t_anim;
    struct pnj_s *next;
} pnj_t;


text_box_t *init_text(char **texte, sfVector2f pos);
void print_text(text_box_t *box, sfRenderWindow *win, sfClock *clock);
#endif /*!PNJ_H_*/
