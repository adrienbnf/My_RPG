/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** init_text
*/

#include "path_assets.h"
#include "pnj.h"

static void init_text_two(text_box_t *text, sfVector2f pos, char **texte)
{
    sfText_setString(text->text, texte[0]);
    sfSprite_setPosition(text->sprite, text->pos);
    sfText_setPosition(text->text, pos);
    sfSprite_setScale(text->sprite, (sfVector2f){0.35, 0.35});
    sfText_setScale(text->text, (sfVector2f){0.20, 0.20});
    sfText_setFont(text->text, text->font);
    sfText_setFillColor(text->text, sfBlack);
    sfSprite_setTexture(text->sprite, text->texture, sfTrue);
}

text_box_t *init_text(char **texte, sfVector2f pos)
{
    text_box_t *text = malloc(sizeof(text_box_t));

    text->texture = sfTexture_createFromFile("./assets/text_back.png", NULL);
    text->sprite = sfSprite_create();
    text->pos = pos;
    text->index = 0;
    text->comment = my_arraydup(texte);
    text->clock = sfClock_create();
    text->text = sfText_create();
    text->write = 0;
    text->tmp = 0;
    text->i = 0;
    text->font = sfFont_createFromFile(path_assets[FONT]);
    init_text_two(text, pos, texte);
    return text;
}
