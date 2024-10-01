/*
** EPITECH PROJECT, 2024
** menu h
** File description:
** contains struct about menus
*/

#ifndef MENU_H
    #include "player.h"
    #include "rpg.h"
    #include "my_menu.h"
    #define MENU_H
    #define ATT_PLUS 0
    #define ATT_MINUS 1
    #define DEF_PLUS 2
    #define DEF_MINUS 3
    #define SPD_PLUS 4
    #define SPD_MINUS 5
    #define HEAL_PLUS 6
    #define HEAL_MINUS 7
    #define MHEAL_PLUS 8
    #define MHEAL_MINUS 9

enum stuff {
    HELMET,
    GOURDIN,
    CHESTPLATE,
    FOOT,
    FRAG1,
    FRAG2,
    FRAG3,
    SWORD
};

static char *stuff_path[] = {
    "assets/helmet_armor.png",
    "assets/gourdin_armor.png",
    "assets/chest_armor.png",
    "assets/pant_armor.png",
    "assets/frag1.png",
    "assets/frag2.png",
    "assets/frag3.png",
    "assets/sword.png"
};

static char *descriptions[] = {
    "It hurts a bit",
    "It permits to\nsurvive at a\nrain of pebbles",
    "jsp",
    "Your heart can't\nbe broken\nanymore",
    "Better to cross\ntall grasses",
    "I'm a very bad\nbottle, you\nshould punish me",
    "A strange piece\nof color..."
    "Perfect to slice\nsausages"
};

typedef struct button {
    char *name;
    sfVector2f size;
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f scale;
    sfSprite *sprite;
    sfTexture *texture;
    char *str_texture;
    sfBool (*is_clicked)(sfRectangleShape *, sfMouseButtonEvent *,
        struct video_s *, struct player_s *);
    sfBool (*is_hover)(sfRectangleShape *, sfMouseMoveEvent *,
        struct video_s *, struct player_s *);
    int state;
} button_t;

typedef struct inv_s {
    int state;
    sfSprite *sprite;
    sfSprite *sprite2;
    sfSprite *sprite3;
    sfTexture *texture;
    sfTexture *texture2;
    sfTexture *texture3;
    sfVector2f pos;
    sfVector2f scale;
    button_t *button1;
    button_t *button2;
    button_t *button3;
    button_t *hand_stuff;
    button_t *helmet_stuff;
    button_t *chest_stuff;
    button_t *foot_stuff;
    button_t *frag_stuff;
    int helmet_equiped;
    int chest_equiped;
    int foot_equiped;
    int hand_equiped;
    int frag_equiped;
    sfText *stats;
    sfText *modif_stat;
    sfText *item_list;
    sfText *item_description;
    button_t *equip_button;
    button_t **plus_minus_buttons;
    button_t *use_button;
    button_t *sup_button;
} inv_t;

typedef struct all_menus_s {
    menu_t *menu;
    inv_t *inventory;
} all_menus_t;


void sound_gestion(video_t *video, all_menus_t *menus, player_t *player);
sfBool is_clicked(sfRectangleShape *rect_but, sfMouseButtonEvent *event,
    struct video_s *video, struct player_s *player);
sfBool is_hover(sfRectangleShape *rect_but, sfMouseMoveEvent *event,
    struct video_s *video, struct player_s *player);
inv_t *content_init_inv(inv_t *inventory, player_t *player);
inv_t *init_inventory(player_t *player);
all_menus_t *init_menus(player_t *player);
void update_item_list(all_menus_t *menus, player_t *player);
void display_items_name(all_menus_t *menus, player_t *player, video_t *video);
char *init_stat_str(player_t *player);
void update_stat(all_menus_t *menus, player_t *player);
void display_stuffs(all_menus_t *menus, player_t *player, video_t *video);
void display_stats(all_menus_t *menus, player_t *player, video_t *video);
void update_stuffs(all_menus_t *menus, player_t *player);
void events_menu(video_t *video, all_menus_t *menus, player_t *player);
all_menus_t *init_menus(player_t *player);
inv_t *init_inventory(player_t *player);
inv_t *content_init_inv(inv_t *inventory, player_t *player);
items_t *init_items(void);
char *init_item_list_str(items_t *items);
sfText *init_item_list(player_t *player);
char *int_to_str(int score);
char **load_array_from_file(char *path);
void display_menus(all_menus_t *menus, player_t *player, video_t *video);
void add_item(items_t **data, char *name, int i);
sfText *init_stats(player_t *player);
void events_inv(video_t *video, sfEvent event, all_menus_t *menus,
    player_t *player);
char *init_item_description_str(items_t *items);
sfText *init_item_description(void);
void update_item_description(all_menus_t *menus, player_t *player);
void display_items_description(all_menus_t *menus, player_t *player,
    video_t *video);
void display_modif_stat(all_menus_t *menus, player_t *player, video_t *video);
void update_modif_stat(all_menus_t *menus, player_t *player);
sfText *init_modif_stat(player_t *player);
char *init_modif_stat_str(player_t *player);
button_t **create_button_arr(button_t **buttons_arr);
void display_plus_minus_buttons(all_menus_t *menus, video_t *video);
void update_plus_minus_buttons(all_menus_t *menus, player_t *player);
button_t *create_button_mheal_minus(button_t *button);
button_t *create_button_mheal_plus(button_t *button);
button_t *create_button_heal_minus(button_t *button);
button_t *create_button_heal_plus(button_t *button);
button_t *create_button_spd_plus(button_t *button);
button_t *create_button_spd_minus(button_t *button);
button_t *create_button_def_minus(button_t *button);
button_t *create_button_def_plus(button_t *button);
button_t *create_button_att_minus(button_t *button);
button_t *create_button_att_plus(button_t *button);
void modify_stat(all_menus_t *menus, player_t *player, int i);
void update_use_button(all_menus_t *menus, player_t *player);
void display_use_button(all_menus_t *menus, video_t *video);
button_t *init_use_button(button_t *button);
void place_button(all_menus_t *menus, button_t *but, int x, int y);
void handle_click_use_button(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event);
void handle_hover_use_button(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event);
void delete_item(items_t **head, int id, all_menus_t *menus, player_t *player);
void update_sup_button(all_menus_t *menus, player_t *player);
void display_sup_button(all_menus_t *menus, video_t *video);
button_t *init_sup_button(button_t *button);
void handle_click_sup_button(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event);
void handle_hover_sup_button(all_menus_t *menus, video_t *video,
    player_t *player, sfEvent event);
void destroy_map1(entities_t *entities, all_menus_t *menus);
void update_frag_stuff(all_menus_t *menus, player_t *player);
void display_frag(all_menus_t *menus, video_t *video);
button_t *init_frag_stuff(void);
char *get_item_value(char *name, char *value);
void update_and_display_victory(player_t *player, video_t *video);
void init_victory(player_t *player);

#endif /* !MENU_H */
