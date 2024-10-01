/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** init_entities_two
*/


#include "inv.h"
#include "player.h"
#include "rpg.h"
#include "ennemy.h"
#include "colision.h"
#include "path_assets.h"
#include "entities.h"
#include "event.h"
#include "my_menu.h"

void init_chest_sprite(chest_t *mob)
{
    mob->cursor_sprite = (sfIntRect){96, MIN_CHEST_IDLE,
    WIDTH_CHEST, HEIGHT_CHEST};
    mob->texture = sfTexture_createFromFile(path_assets[CHEST], NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->cursor_sprite);
    sfSprite_setScale(mob->sprite, (sfVector2f){0.5, 0.5});
}

void init_pnj_sprite(pnj_t *mob)
{
    mob->cursor_sprite = (sfIntRect){MIN_MOB_IDLE, 0,
    HEIGHT_PNJ, WIDTH_PNJ};
    mob->texture = sfTexture_createFromFile(path_assets[PNJ], NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->cursor_sprite);
}

void add_ennemy(ennemy_t **head, ennemy_t *(func)(char *), char *data)
{
    ennemy_t *element = func(data);

    element->next = *head;
    *head = element;
}

void add_chest(chest_t **head, chest_t *(func)(char *), char *data)
{
    chest_t *element = func(data);

    element->next = *head;
    *head = element;
}

void add_pnj(pnj_t **head, pnj_t *(func)(char *, char **), char *data,
    char **texte)
{
    pnj_t *element = func(data, texte);

    element->next = *head;
    *head = element;
}
