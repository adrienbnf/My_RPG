/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** init_sound_bar
*/

#include "my_menu.h"



sfBool is_button_hover_reso(reso_t *button,
    sfMouseButtonEvent *evt, sfVector2f pos, float m)
{
    sfFloatRect tmp = sfRectangleShape_getGlobalBounds(button->hit_box);
    sfVector2f pp = sfRectangleShape_getPosition(button->hit_box);
    int x = (int)pos.x - WIDTH_VIEW / 2;
    int y = (int)pos.y - HEIGHT_VIEW / 2;

    x += (evt->x / (m / (float)(WIDTH_VIEW))) + 8;
    y += (evt->y / (m / (float)(WIDTH_VIEW))) + 8;
    if (sfFloatRect_contains(&tmp, (float)x, (float)y)) {
        button->state = HOVER;
        button->x = x - (pos.x + 45);
        sfRectangleShape_setPosition(button->butt, (VT){x, pp.y});
        return sfTrue;
    }
    button->state = 0;
    return sfFalse;
}

sfBool is_button_hover_soud(sound_t *button,
    sfMouseMoveEvent *evt, sfVector2f pos, float m)
{
    sfFloatRect tmp = sfRectangleShape_getGlobalBounds(button->hit_box);
    sfVector2f pp = sfRectangleShape_getPosition(button->hit_box);
    int x = (int)pos.x - WIDTH_VIEW / 2;
    int y = (int)pos.y - HEIGHT_VIEW / 2;

    x += (evt->x / (m / (float)(WIDTH_VIEW))) + 8;
    y += (evt->y / (m / (float)(WIDTH_VIEW))) + 8;
    if (sfFloatRect_contains(&tmp, (float)x, (float)y)) {
        button->state = HOVER;
        button->x = x - (pos.x - 100);
        sfRectangleShape_setPosition(button->butt, (VT) {x, pp.y});
        return sfTrue;
    }
    button->state = 0;
    return sfFalse;
}

sound_t *init_sound_bar(void)
{
    sound_t *sound_bar = malloc(sizeof(sound_t));

    sound_bar->state = 0;
    sound_bar->x = 20;
    sound_bar->is_hover = &is_button_hover_soud;
    sound_bar->texture = sfTexture_createFromFile("./assets/sound.png", NULL);
    sound_bar->sprites = sfSprite_create();
    sound_bar->hit_box = create_rectangle((VT){500, 500},
    (VT){68, 5}, 1, sfGreen);
    sound_bar->butt = create_rectangle((VT){500, 500},
    (VT){2, 3}, 0, sfRed);
    sound_bar->lock_music = sfFalse;
    sfRectangleShape_setFillColor(sound_bar->butt, sfBlack);
    sfSprite_setTexture(sound_bar->sprites, sound_bar->texture, sfTrue);
    sfSprite_setScale(sound_bar->sprites, (VT){1.1, 1});
    return sound_bar;
}

reso_t *init_reso_bar(void)
{
    reso_t *sound_bar = malloc(sizeof(reso_t));

    sound_bar->state = 0;
    sound_bar->x = 68;
    sound_bar->a = 100;
    sound_bar->a_tmp = 100;
    sound_bar->actual = (sfVector2u){1920, 1080};
    sound_bar->old = (sfVector2u){1920, 1080};
    sound_bar->is_hover = &is_button_hover_reso;
    sound_bar->texture = sfTexture_createFromFile("./assets/reso.png", NULL);
    sound_bar->sprites = sfSprite_create();
    sound_bar->hit_box = create_rectangle((VT){500, 500},
    (VT){68, 5}, 1, sfGreen);
    sound_bar->butt = create_rectangle((VT){500, 500},
    (VT){2, 3}, 0, sfRed);
    sfRectangleShape_setFillColor(sound_bar->butt, sfBlack);
    sfSprite_setTexture(sound_bar->sprites, sound_bar->texture, sfTrue);
    sfSprite_setScale(sound_bar->sprites, (VT){1.1, 1});
    return sound_bar;
}
