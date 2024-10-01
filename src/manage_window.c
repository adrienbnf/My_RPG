/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** Functions related to window management
*/

#include "rpg.h"

sfRenderWindow *init_window(void)
{
    sfRenderWindow *win = NULL;
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2i position = {0, 0};

    win = sfRenderWindow_create(mode,
    "Colorless", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win, 60);
    sfRenderWindow_setPosition(win, position);
    return win;
}
