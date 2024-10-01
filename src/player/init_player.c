/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** init_player
*/

#include "inv.h"
#include "player.h"
#include "path_assets.h"

int get_stat_value(char *stat)
{
    struct stat sb;
    char *buffer = NULL;
    int fd = 0;
    char **arr = NULL;

    lstat("src/save/stat.txt", &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    buffer[sb.st_size] = '\0';
    fd = open("src/save/stat.txt", O_RDONLY | O_CREAT);
    read(fd, buffer, sb.st_size);
    close(fd);
    arr = my_str_to_word_array(buffer, "\n");
    for (int i = 0; arr[i]; i++) {
        if (strncmp(arr[i], stat, strlen(stat)) == 0) {
            return my_getnbr(arr[i]);
        }
    }
    return 0;
}

static sfVector2f init_pos_player(void)
{
    struct stat sb;
    char *buffer = NULL;
    int fd = 0;
    char **arr = NULL;
    int x = 0;
    int y = 0;

    lstat("src/save/coord.txt", &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    buffer[sb.st_size] = '\0';
    fd = open("src/save/coord.txt", O_RDONLY | O_CREAT);
    read(fd, buffer, sb.st_size);
    arr = my_str_to_word_array(buffer, "\n");
    x = my_getnbr(arr[0]);
    y = my_getnbr(arr[1]);
    return (sfVector2f){x, y};
}

static void init_armor(player_t *player)
{
    player->armor[0] = 0;
    player->armor[1] = 0;
    player->armor[2] = 0;
}

static void init_player_states(player_t *player)
{
    player->is_attacking = 0;
    player->atk_active = 0;
    player->is_hurt = 0;
}

static void init_hitboxes_player(player_t *player)
{
    player->hitbox = create_rectangle((sfVector2f){0.0, 0.0},
    (sfVector2f){WIDTH_PLAYER * 0.5, HEIGHT_PLAYER * 0.5}, 0, sfRed);
    player->atk_hitbox = create_rectangle((sfVector2f){0.0, 0.0},
    (sfVector2f){WIDTH_PLAYER * 0.5, HEIGHT_PLAYER * 0.5}, 0, sfGreen);
}

static void init_sprite_player(player_t *player)
{
    player->texture = sfTexture_createFromFile(path_assets[PLAYER], NULL);
    player->texture_fullstuff = sfTexture_createFromFile(path_assets[KNIGHT],
        NULL);
    player->sprite = sfSprite_create();
    sfSprite_setOrigin(player->sprite,
    (sfVector2f){WIDTH_PLAYER / 4, HEIGHT_PLAYER / 4});
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->cursor_sprite = (sfIntRect){MIN_PLAYER_IDLE, 0,
    HEIGHT_PLAYER, WIDTH_PLAYER};
    player->hud = init_hud_player();
    sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
    player->sword_attack = sfMusic_createFromFile(
    "./assets/music/épée_player.ogg");
    player->damage = sfMusic_createFromFile("assets/music/degat_player.ogg");
}

static void init_frag_save(player_t *player)
{
    player->frag_count = get_stat_value("frag_count");
    player->has_to_equip = 0;
}

static void init_frag_default(player_t *player)
{
    player->frag_count = 0;
    player->has_to_equip = 0;
}

player_t *init_player_default(void)
{
    player_t *player = malloc(sizeof(player_t));

    init_sprite_player(player);
    init_hitboxes_player(player);
    init_armor(player);
    init_delta_t(player);
    init_player_states(player);
    player->view = sfView_createFromRect((sfFloatRect){0, 0,
    WIDTH_VIEW, HEIGHT_VIEW});
    player->looking_at = 0;
    player->colision = malloc(sizeof(colision_t));
    player->pos = (sfVector2f){POSX_BEGIN, POSY_BEGIN};
    init_stat_and_xp_default(player);
    init_frag_default(player);
    init_victory(player);
    player->items = NULL;
    player->keys = (keys_t){sfKeyZ, sfKeyS, sfKeyQ, sfKeyD};
    player->vision = create_rectangle((sfVector2f){0, 0},
    (sfVector2f){300, 160}, 0, sfGreen);
    return player;
}

player_t *init_player_saved(void)
{
    player_t *player = malloc(sizeof(player_t));

    init_sprite_player(player);
    init_hitboxes_player(player);
    init_armor(player);
    init_delta_t(player);
    init_player_states(player);
    player->view = sfView_createFromRect((sfFloatRect){0, 0,
    WIDTH_VIEW, HEIGHT_VIEW});
    player->looking_at = 0;
    player->colision = malloc(sizeof(colision_t));
    player->pos = init_pos_player();
    init_stat_and_xp(player);
    init_frag_save(player);
    init_victory(player);
    player->items = init_items();
    player->keys = (keys_t){sfKeyZ, sfKeyS, sfKeyQ, sfKeyD};
    player->vision = create_rectangle((sfVector2f){0, 0},
    (sfVector2f){300, 160}, 0, sfGreen);
    return player;
}
