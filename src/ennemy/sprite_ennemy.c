/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** sprite_ennemy
*/


#include "ennemy.h"
#include "player.h"
#include "path_assets.h"

void init_ennemy_sprite(ennemy_t *mob)
{
    mob->cursor_sprite = (sfIntRect){MIN_MOB_IDLE, 0,
    HEIGHT_ENNEMY, WIDTH_ENNEMY};
    mob->texture = sfTexture_createFromFile(path_assets[GOBELIN], NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->cursor_sprite);
}

void init_ennemy_sprite_orc(ennemy_t *mob)
{
    mob->cursor_sprite = (sfIntRect){MIN_MOB_IDLE, 0,
    HEIGHT_ENNEMY, WIDTH_ENNEMY};
    mob->texture = sfTexture_createFromFile(
    "assets/characters/Orc-Grunt.png", NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->cursor_sprite);
}

void init_ennemy_sprite_mage(ennemy_t *mob)
{
    mob->cursor_sprite = (sfIntRect){MIN_MOB_IDLE, 0,
    HEIGHT_ENNEMY, WIDTH_ENNEMY};
    mob->texture = sfTexture_createFromFile(
    "./assets/characters/Mage-Red.png", NULL);
    mob->sprite = sfSprite_create();
    sfSprite_setTexture(mob->sprite, mob->texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->cursor_sprite);
}
