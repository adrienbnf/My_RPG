/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** change_resolution
*/

#include "my_menu.h"
#include "rpg.h"


static sfVector2u get_reso(menu_t *menu)
{
    if (menu->reso_bar->a < 12.5 * 1)
        return (sfVector2u){640, 360};
    if (menu->reso_bar->a < 12.5 * 2)
        return (sfVector2u){854, 480};
    if (menu->reso_bar->a < 12.5 * 3)
        return (sfVector2u){960, 540};
    if (menu->reso_bar->a < 12.5 * 4)
        return (sfVector2u){1024, 576};
    if (menu->reso_bar->a < 12.5 * 5)
        return (sfVector2u){1280, 720};
    if (menu->reso_bar->a < 12.5 * 6)
        return (sfVector2u){1366, 768};
    if (menu->reso_bar->a < 12.5 * 7)
        return (sfVector2u){1600, 900};
    if (menu->reso_bar->a < 12.5 * 8)
        return (sfVector2u){1920, 1080};
    return (sfVector2u){1920, 1080};
}

static void change_reso(menu_t *menu)
{
    menu->reso_bar->old = menu->old;
    menu->reso_bar->actual = menu->actual;
}

void change_resolution(video_t *video, menu_t *menu)
{
    menu->reso_bar->a = abs(menu->reso_bar->x * 100 / 68);
    if (abs(menu->reso_bar->a - menu->reso_bar->a_tmp) >= 12.5) {
        menu->reso_bar->a_tmp = menu->reso_bar->a;
        menu->old = menu->actual;
        menu->actual = get_reso(menu);
        change_reso(menu);
        sfRenderWindow_setSize(video->win, menu->actual);
    }
}
