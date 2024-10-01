/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** intro
*/

#include "path_assets.h"
#include "rpg.h"

logo_t *init_logo(void)
{
    logo_t *logo = malloc(sizeof(logo_t));

    logo->texture = sfTexture_createFromFile(path_assets[LOGO], NULL);
    logo->sprite = sfSprite_create();
    logo->scale = (sfVector2f){0.1, 0.1};
    logo->t_anim = 0;
    logo->scale_up = sfTrue;
    sfSprite_setTexture(logo->sprite, logo->texture, sfTrue);
    sfSprite_setPosition(logo->sprite, (sfVector2f){980.0, 500.0});
    sfSprite_setOrigin(logo->sprite, (sfVector2f){333, 188});
    sfSprite_setScale(logo->sprite, logo->scale);
    return logo;
}

void animate_logo(logo_t *logo, video_t *video, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - logo->t_anim > 0.01 && logo->scale_up){
        logo->scale.x += 0.025;
        logo->scale.y += 0.025;
        logo->t_anim = seconds;
    }
    if (logo->scale.x >= 2.0)
        logo->scale_up = sfFalse;
    sfSprite_setScale(logo->sprite, logo->scale);
    sfRenderWindow_drawSprite(video->win, logo->sprite, NULL);
}

static int handle_closed_window_intro(video_t *video)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(video->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(video->win);
    }
}

int intro_loop(video_t *video)
{
    logo_t *logo = init_logo();
    double sec =
    sfClock_getElapsedTime(video->clock).microseconds / 1000000.0;
    double begin = sec;

    while (sfRenderWindow_isOpen(video->win) && (sec - begin) < 4.0){
        handle_closed_window_intro(video);
        sfRenderWindow_clear(video->win, sfBlack);
        animate_logo(logo, video, video->clock);
        sfRenderWindow_display(video->win);
        sec = sfClock_getElapsedTime(video->clock).microseconds / 1000000.0;
    }
}
