/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** init_sound_bar
*/

#include "my_menu.h"


sfBool just_but(struct simple_but_s *button,
    sfMouseButtonEvent *evt, sfVector2f pos, float m)
{
    sfFloatRect tmp = sfRectangleShape_getGlobalBounds(button->but);
    int x = (int)pos.x - WIDTH_VIEW / 2;
    int y = (int)pos.y - HEIGHT_VIEW / 2;

    x += (evt->x / (m / (float)(WIDTH_VIEW))) + 8;
    y += (evt->y / (m / (float)(WIDTH_VIEW))) + 8;
    if (sfFloatRect_contains(&tmp, (float)x, (float)y)) {
        button->state = PRESSED;
        return sfTrue;
    }
    return sfFalse;
}

simple_but_t *init_azerty(void)
{
    simple_but_t *sound_bar = malloc(sizeof(simple_but_t));

    sound_bar->state = 0;
    sound_bar->is_hover = &just_but;
    sound_bar->texture = sfTexture_createFromFile("./assets/azerty.png", NULL);
    sound_bar->sprites = sfSprite_create();
    sound_bar->but = create_rectangle((VT){500, 500},
    (VT){50, 15}, 1, sfRed);
    sfSprite_setTexture(sound_bar->sprites, sound_bar->texture, sfTrue);
    sfSprite_setScale(sound_bar->sprites, (VT){1, 1});
    return sound_bar;
}

simple_but_t *init_qwerty(void)
{
    simple_but_t *sound_bar = malloc(sizeof(simple_but_t));

    sound_bar->state = 0;
    sound_bar->is_hover = &just_but;
    sound_bar->texture = sfTexture_createFromFile("./assets/qwerty.png", NULL);
    sound_bar->sprites = sfSprite_create();
    sound_bar->but = create_rectangle((VT){500, 500},
    (VT){50, 15}, 1, sfRed);
    sfSprite_setTexture(sound_bar->sprites, sound_bar->texture, sfTrue);
    sfSprite_setScale(sound_bar->sprites, (VT){1, 1});
    return sound_bar;
}
