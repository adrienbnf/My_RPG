/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** Functions related to player management
*/

#include "colision.h"
#include "path_assets.h"
#include "player.h"

static void check_level_up(player_t *player)
{
    while (player->xp->xp >= player->xp->target_xp){
        player->xp->credit += CREDIT_PER_LEVEL;
        player->xp->level++;
        player->xp->xp -= player->xp->target_xp;
        player->xp->target_xp += DELTA_XP_TARGET;
        player->stat->max_health += 10;
        player->stat->health = player->stat->max_health;
    }
}

static void set_looking_at_player(player_t *player, sfVector2f dir)
{
    player->looking_at = dir.y > 0 ? 0 : player->looking_at;
    player->looking_at = dir.x > 0 ? 1 : player->looking_at;
    player->looking_at = dir.y < 0 ? 2 : player->looking_at;
    player->looking_at = dir.x < 0 ? 3 : player->looking_at;
}

static void handle_input(player_t *player, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    keys_t keys = player->keys;

    player->direction = (sfVector2f){0.0, 0.0};
    if (sfKeyboard_isKeyPressed(keys.up) && arrows_input(player, UP))
        player->direction.y -= 1.0;
    if (sfKeyboard_isKeyPressed(keys.down) && arrows_input(player, DOWN))
        player->direction.y += 1.0;
    if (sfKeyboard_isKeyPressed(keys.right) && arrows_input(player, RIGHT))
        player->direction.x += 1.0;
    if (sfKeyboard_isKeyPressed(keys.left) && arrows_input(player, LEFT))
        player->direction.x -= 1.0;
    normalize(&player->direction);
    player->pos.x += player->direction.x *
    player->stat->speed * (seconds - player->t_move);
    player->pos.y += player->direction.y *
    player->stat->speed * (seconds - player->t_move);
    set_looking_at_player(player, player->direction);
    player->t_move = seconds;
}

static void set_kb_vector_player(player_t *player, ennemy_t *ennemy)
{
    if (ennemy->looking_at == 0 || ennemy->looking_at == 2){
        player->kb_vector.x = (ennemy->looking_at == 0) ? 1 : -1;
        player->kb_vector.y = VERTICAL_KB;
    }
    if (ennemy->looking_at == 1 || ennemy->looking_at == 3){
        player->kb_vector.x = (ennemy->looking_at == 1) ? 1 : -1;
        player->kb_vector.y = HORIZONTAL_KB;
    }
}

void naked_sprite_player(player_t *player)
{
    sfTexture *new = NULL;

    if (!player->armor[0] || !player->armor[1] || !player->armor[2]){
        new = sfTexture_createFromFile(path_assets[PLAYER], NULL);
        sfSprite_setTexture(player->sprite, new, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
    }
}

void put_armor_sprite_player(player_t *player)
{
    if (player->armor[0] && player->armor[1] && player->armor[2]){
        sfSprite_setTexture(player->sprite, player->texture_fullstuff, sfTrue);
        sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
    }
}

static void knock_back_player(player_t *player, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    double delta_t = seconds - player->t_move;
    int direction_kb = 0;
    sfVector2f future_pos = player->pos;

    if (player->kb_vector.y == VERTICAL_KB)
        future_pos.y += KB_POWER_PLAYER * (delta_t) * (player->kb_vector.x);
    if (player->kb_vector.y == HORIZONTAL_KB)
        future_pos.x += KB_POWER_PLAYER * (delta_t) * (player->kb_vector.x);
    if (colision_e(player, future_pos))
        player->pos = future_pos;
    player->t_move = seconds;
}

static void check_if_hurt(player_t *player, ennemy_t *ennemy)
{
    int damage = 0;
    ennemy_t *tmp = ennemy;

    while (tmp != NULL){
        if (rect_are_colliding(player->hitbox, tmp->hit_box)){
            player->cursor_sprite.left = MIN_PLAYER_HURT;
            sfMusic_play(player->damage);
            player->is_hurt = 1;
            player->is_attacking = 0;
            player->atk_active = 0;
            damage = tmp->stat->attack - player->stat->defense;
            player->stat->health -= (damage < 0) ? 0 : damage;
            set_kb_vector_player(player, tmp);
            return;
        }
        tmp = tmp->next;
    }
}

void player_loop(player_t *player, video_t *video, ennemy_t *ennemy)
{
    check_level_up(player);
    if (!player->is_hurt){
        handle_input(player, video->clock);
        handle_attack(player);
        check_if_hurt(player, ennemy);
    } else
        knock_back_player(player, video->clock);
    sfSprite_setPosition(player->sprite, player->pos);
    animate_player(player, player->direction, video->clock);
    display_hud_player(player, video);
    sfView_setCenter(player->view, (sfVector2f){player->pos.x + 8,
    player->pos.y + 8});
    sfRectangleShape_setPosition(player->vision, (sfVector2f)
    {player->pos.x - 140, player->pos.y - 80});
    sfRectangleShape_setPosition(player->hitbox, player->pos);
    sfRenderWindow_setView(video->win, player->view);
}
