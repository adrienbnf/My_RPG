/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** place_menu
*/

#include "my_menu.h"
#include "player.h"

static void place_bar_sound(menu_t *menu, int x, int y, video_t *video)
{
    if (menu->sound_bar->vol == 1)
        menu->sound_bar->vol = 0;
    sfRectangleShape_setPosition(menu->sound_bar->butt,
    (VT){x - 100 + menu->sound_bar->x, y - 22});
    sfRectangleShape_setPosition(menu->sound_bar->hit_box,
    (VT){x - 100, y - 23});
    sfSprite_setPosition(menu->sound_bar->sprites, (VT){x - 105, y - 40});
    sfRenderWindow_drawSprite(video->win, menu->sound_bar->sprites, NULL);
    sfRenderWindow_drawRectangleShape(video->win,
    menu->sound_bar->butt, NULL);
}

static void place_bar_reso(menu_t *menu, int x, int y, video_t *video)
{
    sfRectangleShape_setPosition(menu->reso_bar->butt,
        (VT){x + 45 + menu->reso_bar->x, y - 22});
    sfRectangleShape_setPosition(menu->reso_bar->hit_box,
    (VT){x + 46, y - 23});
    sfSprite_setPosition(menu->reso_bar->sprites, (VT){x + 40, y - 40});
    sfRenderWindow_drawSprite(video->win, menu->reso_bar->sprites, NULL);
    sfRenderWindow_drawRectangleShape(video->win, menu->reso_bar->butt, NULL);
}

static void place_save_exit_quit(menu_t *menu, int x, int y, video_t *video)
{
    sfRenderWindow_drawSprite(video->win, menu->exit_button->sprites, NULL);
    sfRectangleShape_setPosition(menu->exit_button->but,
    (VT){x + 110, y - 60});
    sfSprite_setPosition(menu->exit_button->sprites, (VT){x + 109, y - 60});
    sfRenderWindow_drawSprite(video->win, menu->save_button->sprites, NULL);
    sfRectangleShape_setPosition(menu->save_button->but,
    (VT){x - 60, y + 50});
    sfSprite_setPosition(menu->save_button->sprites, (VT){x - 60, y + 50});
    sfRenderWindow_drawSprite(video->win, menu->quit_button->sprites, NULL);
    sfRectangleShape_setPosition(menu->quit_button->but,
    (VT){x + 30, y + 50});
    sfSprite_setPosition(menu->quit_button->sprites, (VT){x + 30, y + 50});
}

static void place_keys(menu_t *menu, int x, int y, video_t *video)
{
    sfRenderWindow_drawSprite(video->win, menu->azerty_button->sprites, NULL);
    sfRectangleShape_setPosition(menu->azerty_button->but,
    (VT){x - 80, y + 15});
    sfSprite_setPosition(menu->azerty_button->sprites, (VT){x - 80, y + 15});
    sfRenderWindow_drawSprite(video->win, menu->qwerty_button->sprites, NULL);
    sfRectangleShape_setPosition(menu->qwerty_button->but,
    (VT){x + 50, y + 15});
    sfSprite_setPosition(menu->qwerty_button->sprites, (VT){x + 50, y + 15});
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->background = create_rectangle((VT){0, 0},
        (VT){2500, 2500}, 0, sfBlack);
    sfRectangleShape_setFillColor(menu->background,
    sfColor_fromRGBA(0, 0, 0, 150));
    menu->open = 0;
    menu->actual = (sfVector2u){1920, 1080};
    menu->reso_bar = init_reso_bar();
    menu->sound_bar = init_sound_bar();
    menu->exit_button = init_exit();
    menu->save_button = init_save();
    menu->quit_button = init_quit();
    menu->azerty_button = init_azerty();
    menu->qwerty_button = init_qwerty();
    return menu;
}

void place_menu(menu_t *menu, player_t *p, video_t *video)
{
    int y = p->pos.y;
    int x = p->pos.x;

    menu->pos = p->pos;
    change_resolution(video, menu);
    sfRenderWindow_drawRectangleShape(video->win, menu->background, NULL);
    place_bar_sound(menu, x, y, video);
    place_bar_reso(menu, x, y, video);
    place_save_exit_quit(menu, x, y, video);
    place_keys(menu, x, y, video);
}
