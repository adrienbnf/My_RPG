/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** Header of the project
*/

#ifndef RPG_H_
    #define RPG_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #include "my.h"
    #include "csfml_tool.h"
    #define UP 1
    #define DOWN 2
    #define RIGHT 3
    #define LEFT 4
    #define HEIGHT_VIEW 144
    #define WIDTH_VIEW 256

enum sprites {
    PLAYER,
    MAP_1_OUTSIDE_1,
    MAP_1_OUTSIDE_2,
    MAP_1_COLISION,
    GOBELIN,
    MAIN_MENU_BG,
    MAIN_MENU_BUTT,
    MAIN_MENU_BUTT_START,
    MAIN_MENU_BUTT_CONTINUE,
    MAIN_MENU_BUTT_QUIT,
    PNJ,
    CHEST,
    KNIGHT,
    HUD,
    FONT,
    LOGO
};

typedef struct colision_s {
    char **map;
    char **map_copy;
    sfVector2f pos_player;
} colision_t;

typedef struct video_s {
    sfTexture *back_p;
    sfMusic *music;
    sfSprite *back_player;
    sfTexture *front_p;
    sfSprite *front_player;
    sfRenderWindow *win;
    sfClock *clock;
    sfShader *shader;
    sfRenderStates states;
    sfBool isGray;
    sfBool restoreSomeColor;
    sfBool restoreMoreColor;
    sfBool restoreFullColor;
} video_t;

typedef struct bg_s {
    sfTexture *texture;
    sfSprite *sprite;
} bg_t;

typedef struct stat_s {
    int attack;
    int defense;
    int health;
    int speed;
    int max_health;
} stat_t;

typedef struct logo_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfBool scale_up;
    float max_scale;
    double t_anim;
} logo_t;

void destroy_video(video_t *video);
int open_all(void);
sfRenderWindow *init_window(void);
void normalize(sfVector2f *);
int array_len(char **array);
stat_t *dup_stats(stat_t stat);
int save_files_correct(void);
int intro_loop(video_t *video);
void animate_logo(logo_t *logo, video_t *video, sfClock *clock);
void apply_colors(video_t *video);

#endif /* !RPG_H_ */
