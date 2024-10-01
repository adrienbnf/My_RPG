/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** Header related to player
*/

#ifndef PLAYER_H_
    #include "rpg.h"
    #include "entities.h"
    #define PLAYER_H_
    #define TARGET_XP_BASE 10
    #define DELTA_XP_TARGET 25
    #define CREDIT_PER_LEVEL 10
    #define HEIGHT_PLAYER 32
    #define WIDTH_PLAYER 32
    #define BASE_PLAYER_SPEED 45
    #define BASE_PLAYER_HEALTH 100
    #define BASE_PLAYER_DEFENSE 0
    #define BASE_PLAYER_ATK 25
    #define ACTIVE_ATTACK_FRAME 224
    #define OFFSET_ANIM_PLAYER 32
    #define MAX_PLAYER_HURT MAX_MOB_HURT
    #define MIN_PLAYER_HURT MIN_MOB_HURT
    #define KB_POWER_PLAYER 70
    #define MIN_PLAYER_IDLE 0
    #define MAX_PLAYER_IDLE 64
    #define MIN_PLAYER_MOVE 32
    #define MAX_PLAYER_MOVE 160
    #define MIN_PLAYER_ATK 160
    #define MAX_PLAYER_ATK 288
    #define MIN_PLAYER_DEAD 702
    #define MIN_PLAYER_SLEEP 734
    #define MAX_PLAYER_DEAD 798
    #define POSX_BEGIN 976.0
    #define POSY_BEGIN 1328.0

typedef struct xp_s {
    int target_xp;
    int xp;
    int level;
    int credit;
} xp_t;

typedef struct items_s {
    char *class;
    char *name;
    int id;
    int id_description;
    int equiped;
    struct stat_s *stat;
    sfRectangleShape *rect;
    int rect_visible;
    struct items_s *next;
    struct items_s *prev;
} items_t;

typedef struct hud_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *level;
    sfRectangleShape *health;
    sfRectangleShape *xp;
    sfVector2f pos;
} hud_t;

typedef struct keys_s {
    int up;
    int down;
    int left;
    int right;
} keys_t;

typedef struct player_s {
    sfMusic *sword_attack;
    sfMusic *damage;
    sfRectangleShape *vision;
    sfTexture *texture;
    sfTexture *texture_fullstuff;
    sfSprite *sprite;
    sfIntRect cursor_sprite;
    double t_anim;
    double t_move;
    int is_attacking;
    int armor[3];
    int is_hurt;
    sfVector2i kb_vector;
    int atk_active;
    sfVector2f direction;
    int looking_at;
    sfRectangleShape *hitbox;
    sfRectangleShape *atk_hitbox;
    sfVector2f pos;
    sfView *view;
    struct colision_s *colision;
    stat_t *stat;
    xp_t *xp;
    items_t *items;
    keys_t keys;
    int frag_count;
    int has_to_equip;
    hud_t *hud;
    sfTexture *victory_texture;
    sfSprite *victory_sprite;
} player_t;



void move_ennemy(player_t *p, ennemy_t *e, sfClock *clock);
stat_t *init_default_player_stat(void);
xp_t *init_default_player_xp(void);
player_t *init_player_default(void);
player_t *init_player_saved(void);
void player_loop(player_t *, video_t *, ennemy_t *);
void handle_attack(player_t *player);
void animate_player(player_t *, sfVector2f, sfClock *);
void loop_ennemy(video_t *video, ennemy_t **ennemy, player_t *p);
void loop_pnj(pnj_t *pnj, player_t *player, video_t *video);
void loop_chest(chest_t *chest, player_t *player, video_t *video);
void entities_loop(entities_t *entities, video_t *video, player_t *player);
int colision_e(player_t *p, sfVector2f r);
void set_looking_at(ennemy_t *mob, player_t *player);
void destroy_player(player_t *player);
int len_items(items_t *items);
void put_armor_sprite_player(player_t *player);
void naked_sprite_player(player_t *player);
void init_delta_t(player_t *player);
void init_stat_and_xp_default(player_t *player);
void init_stat_and_xp(player_t *player);
int get_stat_value(char *stat);
hud_t *init_hud_player(void);
void display_hud_player(player_t *p, video_t *video);

#endif /* !PLAYER_H_ */
