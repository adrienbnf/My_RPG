/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** my_menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "rpg.h"
    #include "player.h"
    #include "entities.h"

    #define HOVER 1
    #define PRESSED 2
    #define VT sfVector2f
    #define SB sound_bar
    #define NEW_GAME 1
    #define CONTINUE 2
    #define QUIT_MM 3
    #define H_MM_BUTTON 32
    #define W_MM_BUTTON 96
    #define MAX_SPRITE_MM_BUTTON 768
    #define NB_BUTTON_MM 3
typedef struct mm_buttons_s {
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect cursor_sprite;
    int quit_menu;
    int hovered;
    int clicked;
    int type;
    double t_anim;
} mm_buttons_t;

typedef struct main_menu_s {
    bg_t bg;
    mm_buttons_t **buttons;
} main_menu_t;

typedef struct sound_s {
    sfTexture *texture;
    sfSprite *sprites;
    sfRectangleShape *hit_box;
    sfRectangleShape *butt;
    int state;
    sfBool lock_music;
    sfVector2f pos;
    int x;
    int vol;
    sfBool (*is_hover)(struct sound_s *, sfMouseMoveEvent *, sfVector2f,
        float);
} sound_t;

typedef struct reso_s {
    sfTexture *texture;
    sfSprite *sprites;
    sfRectangleShape *hit_box;
    sfRectangleShape *butt;
    int state;
    sfVector2f pos;
    sfVector2u actual;
    sfVector2u old;
    int x;
    int a;
    int a_tmp;
    sfBool (*is_hover)(struct reso_s *, sfMouseButtonEvent *, sfVector2f,
        float);
} reso_t;

typedef struct simple_but_s {
    sfTexture *texture;
    sfSprite *sprites;
    sfRectangleShape *but;
    int state;
    sfBool (*is_hover)(struct simple_but_s *,
        sfMouseButtonEvent *, sfVector2f, float);
} simple_but_t;

typedef struct menu_s {
    sfVector2f pos;
    reso_t *reso_bar;
    simple_but_t *exit_button;
    simple_but_t *save_button;
    simple_but_t *quit_button;
    simple_but_t *azerty_button;
    simple_but_t *qwerty_button;
    sound_t *sound_bar;
    sfVector2u actual;
    sfVector2u old;
    sfRectangleShape *background;
    int open;
} menu_t;


void keys_gestion(player_t *p, sfEvent event, menu_t *menu, video_t *v);
void change_resolution(video_t *video, menu_t *menu);
void menu_event(video_t *video, menu_t *menu, sfEvent event, player_t *player);
sfBool just_but(struct simple_but_s *button, sfMouseButtonEvent *evt,
    sfVector2f pos, float m);
void place_menu(menu_t *menu, player_t *p, video_t *video);
menu_t *init_menu(void);
simple_but_t *init_qwerty(void);
simple_but_t *init_azerty(void);
simple_but_t *init_quit(void);
reso_t *init_reso_bar(void);
simple_but_t *init_save(void);
simple_but_t *init_exit(void);
void window_loop(video_t *, menu_t *);
sound_t *init_sound_bar(void);
int main_menu_scene(video_t *video);
main_menu_t *init_main_menu(void);
void game_over_animation(player_t *player, video_t *video, sfClock *clock);
void map_one(player_t *player, video_t *video);
void destroy_video(video_t *video);

#endif /* !MENU_H_ */
