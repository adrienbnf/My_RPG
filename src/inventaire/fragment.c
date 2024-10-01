/*
** EPITECH PROJECT, 2024
** fragment
** File description:
** frgament
*/

#include "inv.h"
#include "player.h"

button_t *init_frag_stuff(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->pos = (sfVector2f){0, 0};
    button->scale = (sfVector2f){0.3, 0.3};
    button->size = (sfVector2f){22, 22};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = strdup("frag");
    button->rect = sfRectangleShape_create();
    button->sprite = sfSprite_create();
    button->str_texture = NULL;
    sfSprite_setOrigin(button->sprite, (sfVector2f){278.5, 201});
    sfSprite_setScale(button->sprite, button->scale);
    sfRectangleShape_setOrigin(button->rect, (sfVector2f){11, 11});
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfRed);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

void update_frag_stuff(all_menus_t *menus, player_t *player)
{
    if (menus->inventory->frag_stuff->str_texture != NULL &&
        player->frag_count != player->has_to_equip) {
        menus->inventory->frag_stuff->texture =
            sfTexture_createFromFile(menus->inventory->
                frag_stuff->str_texture, NULL);
        sfSprite_setTexture(menus->inventory->frag_stuff->sprite,
            menus->inventory->frag_stuff->texture, sfTrue);
        player->has_to_equip++;
    }
    menus->inventory->frag_stuff->pos =
    sfSprite_getPosition(menus->inventory->sprite);
    sfSprite_setPosition(menus->inventory->frag_stuff->sprite,
        menus->inventory->frag_stuff->pos);
    sfRectangleShape_setPosition(menus->inventory->frag_stuff->rect,
        (sfVector2f){menus->inventory->frag_stuff->pos.x - 36,
            menus->inventory->frag_stuff->pos.y - 20});
}

void display_frag(all_menus_t *menus, video_t *video)
{
    if (menus->inventory->frag_stuff->str_texture != NULL) {
        sfRenderWindow_drawSprite(video->win,
            menus->inventory->frag_stuff->sprite, NULL);
    }
}
