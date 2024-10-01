/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** init_sound_bar
*/

#include "my_menu.h"

simple_but_t *init_exit(void)
{
    simple_but_t *sound_bar = malloc(sizeof(simple_but_t));

    sound_bar->state = 0;
    sound_bar->texture = sfTexture_createFromFile("./assets/QUIT.png", NULL);
    sound_bar->sprites = sfSprite_create();
    sound_bar->is_hover = &just_but;
    sound_bar->but = create_rectangle((VT){500, 500},
    (VT){15, 15}, 1, sfRed);
    sfSprite_setTexture(sound_bar->sprites, sound_bar->texture, sfTrue);
    sfSprite_setScale(sound_bar->sprites, (VT){1, 1});
    return sound_bar;
}

simple_but_t *init_save(void)
{
    simple_but_t *sound_bar = malloc(sizeof(simple_but_t));

    sound_bar->state = 0;
    sound_bar->is_hover = &just_but;
    sound_bar->texture = sfTexture_createFromFile("./assets/save.png", NULL);
    sound_bar->sprites = sfSprite_create();
    sound_bar->but = create_rectangle((VT){500, 500},
    (VT){50, 15}, 1, sfRed);
    sfSprite_setTexture(sound_bar->sprites, sound_bar->texture, sfTrue);
    sfSprite_setScale(sound_bar->sprites, (VT){1, 1});
    return sound_bar;
}

simple_but_t *init_quit(void)
{
    simple_but_t *sound_bar = malloc(sizeof(simple_but_t));

    sound_bar->state = 0;
    sound_bar->is_hover = &just_but;
    sound_bar->texture = sfTexture_createFromFile("./assets/quit.png", NULL);
    sound_bar->sprites = sfSprite_create();
    sound_bar->but = create_rectangle((VT){500, 500},
    (VT){50, 15}, 1, sfRed);
    sfSprite_setTexture(sound_bar->sprites, sound_bar->texture, sfTrue);
    sfSprite_setScale(sound_bar->sprites, (VT){1, 1});
    return sound_bar;
}
