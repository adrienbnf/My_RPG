/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** game_over
*/

#include "my_menu.h"
#include "player.h"

static int check_close_game(video_t *video)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(video->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(video->win);
    }
}

static sfRectangleShape *init_gameover_gradient(void)
{
    sfRectangleShape *bg = sfRectangleShape_create();

    sfRectangleShape_setSize(bg, (sfVector2f){3000.0, 3000.0});
    sfRectangleShape_setPosition(bg, (sfVector2f){0.0, 0.0});
    return bg;
}

static sfColor set_black_gradient(double *sec, double *t_anim, int *a,
    sfRectangleShape *bg)
{
    sfColor bg_color = sfColor_fromRGBA(0, 0, 0, 0);

    if (*a < 255 && *sec - *t_anim > 0.03){
            *a = *a + 1;
            *t_anim = *sec;
    }
    bg_color.a = *a;
    sfRectangleShape_setFillColor(bg, bg_color);
}

void animate_player_death(player_t *player, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - player->t_anim > 0.6){
        player->cursor_sprite.left += OFFSET_ANIM_PLAYER;
        player->t_anim = seconds;
    }
    if (player->cursor_sprite.left < MIN_PLAYER_DEAD)
        player->cursor_sprite.left = MIN_PLAYER_DEAD;
    if (player->cursor_sprite.left >= MAX_PLAYER_DEAD)
        player->cursor_sprite.left = MIN_PLAYER_SLEEP;
    sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
}

static void reset_shader(video_t *video)
{
    video->isGray = sfTrue;
    video->restoreFullColor = sfFalse;
    video->restoreMoreColor = sfFalse;
    video->restoreSomeColor = sfFalse;
    apply_colors(video);
}

void reload_save(player_t *player, video_t *video)
{
    player_t *new_player = NULL;

    reset_shader(video);
    destroy_player(player);
    new_player = init_player_default();
    map_one(new_player, video);
}

void game_over_animation(player_t *player, video_t *video, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    double t_anim = seconds;
    double begin = seconds;
    int alpha = 0;
    sfRectangleShape *bg = init_gameover_gradient();

    player->cursor_sprite.left = 32;
    sfSprite_setTextureRect(player->sprite, player->cursor_sprite);
    player->t_anim = seconds;
    while (sfRenderWindow_isOpen(video->win) && seconds - begin < 6.0){
        seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        check_close_game(video);
        set_black_gradient(&seconds, &t_anim, &alpha, bg);
        sfRenderWindow_drawRectangleShape(video->win, bg, NULL);
        if (alpha >= 88)
            animate_player_death(player, clock);
        sfRenderWindow_drawSprite(video->win, player->sprite, NULL);
        sfRenderWindow_display(video->win);
    }
    reload_save(player, video);
}
