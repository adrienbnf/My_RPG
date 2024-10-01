/*
** EPITECH PROJECT, 2024
** menus
** File description:
** contains func about menus
*/

#include "player.h"
#include "inv.h"
#include "rpg.h"
#include "my_menu.h"

button_t **create_button_arr(button_t **buttons_arr)
{
    buttons_arr = malloc(sizeof(button_t *) * 11);
    buttons_arr[ATT_PLUS] = create_button_att_plus(buttons_arr[ATT_PLUS]);
    buttons_arr[ATT_MINUS] = create_button_att_minus(buttons_arr[ATT_PLUS]);
    buttons_arr[DEF_PLUS] = create_button_def_plus(buttons_arr[ATT_PLUS]);
    buttons_arr[DEF_MINUS] = create_button_def_minus(buttons_arr[ATT_PLUS]);
    buttons_arr[SPD_PLUS] = create_button_spd_plus(buttons_arr[ATT_PLUS]);
    buttons_arr[SPD_MINUS] = create_button_spd_minus(buttons_arr[ATT_PLUS]);
    buttons_arr[HEAL_PLUS] = create_button_heal_plus(buttons_arr[ATT_PLUS]);
    buttons_arr[HEAL_MINUS] = create_button_heal_minus(buttons_arr[ATT_PLUS]);
    buttons_arr[MHEAL_PLUS] = create_button_mheal_plus(buttons_arr[ATT_PLUS]);
    buttons_arr[MHEAL_MINUS] =
        create_button_mheal_minus(buttons_arr[ATT_PLUS]);
    buttons_arr[10] = NULL;
    return buttons_arr;
}

static button_t *init_button_inv_page(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->pos = (sfVector2f){0, 0};
    button->size = (sfVector2f){30, 10};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = strdup("next page");
    button->rect = sfRectangleShape_create();
    button->state = 0;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfRed);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

static button_t *init_chest_stuff(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->pos = (sfVector2f){0, 0};
    button->scale = (sfVector2f){0.3, 0.3};
    button->size = (sfVector2f){22, 22};
    button->is_hover = &is_hover;
    button->name = strdup("chest");
    button->rect = sfRectangleShape_create();
    button->sprite = sfSprite_create();
    button->str_texture = NULL;
    sfSprite_setOrigin(button->sprite, (sfVector2f){278.5, 201});
    sfSprite_setScale(button->sprite, button->scale);
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

static button_t *init_foot_stuff(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->pos = (sfVector2f){0, 0};
    button->scale = (sfVector2f){0.3, 0.3};
    button->size = (sfVector2f){22, 22};
    button->is_hover = &is_hover;
    button->name = strdup("foot");
    button->rect = sfRectangleShape_create();
    button->sprite = sfSprite_create();
    button->str_texture = NULL;
    sfSprite_setOrigin(button->sprite, (sfVector2f){278.5, 201});
    sfSprite_setScale(button->sprite, button->scale);
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfGreen);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

static button_t *init_hand_stuff(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->pos = (sfVector2f){0, 0};
    button->scale = (sfVector2f){0.3, 0.3};
    button->size = (sfVector2f){22, 22};
    button->is_hover = &is_hover;
    button->name = strdup("hand");
    button->rect = sfRectangleShape_create();
    button->sprite = sfSprite_create();
    button->str_texture = NULL;
    sfSprite_setOrigin(button->sprite, (sfVector2f){278.5, 201});
    sfSprite_setScale(button->sprite, button->scale);
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

static button_t *init_helmet_stuff(void)
{
    button_t *button = malloc(sizeof(button_t));

    button->pos = (sfVector2f){0, 0};
    button->scale = (sfVector2f){0.3, 0.3};
    button->size = (sfVector2f){22, 22};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = strdup("helmet");
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

inv_t *content_init_inv(inv_t *inventory, player_t *player)
{
    inventory->scale = (sfVector2f){0.3, 0.3};
    inventory->pos = (sfVector2f){0, 0};
    inventory->state = 0;
    inventory->button1 = init_button_inv_page();
    inventory->button2 = init_button_inv_page();
    inventory->button3 = init_button_inv_page();
    inventory->chest_stuff = init_chest_stuff();
    inventory->helmet_stuff = init_helmet_stuff();
    inventory->hand_stuff = init_hand_stuff();
    inventory->foot_stuff = init_foot_stuff();
    inventory->frag_stuff = init_frag_stuff();
    inventory->stats = init_stats(player);
    inventory->modif_stat = init_modif_stat(player);
    inventory->item_list = init_item_list(player);
    inventory->item_description = init_item_description();
    inventory->plus_minus_buttons = create_button_arr(inventory->
        plus_minus_buttons);
    inventory->use_button = init_use_button(inventory->use_button);
    inventory->sup_button = init_sup_button(inventory->use_button);
    return inventory;
}

static inv_t *set_texture(inv_t *inventory)
{
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    sfSprite_setScale(inventory->sprite, inventory->scale);
    sfSprite_setOrigin(inventory->sprite, (sfVector2f){278.5, 201});
    sfSprite_setTexture(inventory->sprite2, inventory->texture2, sfTrue);
    sfSprite_setScale(inventory->sprite2, inventory->scale);
    sfSprite_setOrigin(inventory->sprite2, (sfVector2f){278.5, 201});
    sfSprite_setTexture(inventory->sprite3, inventory->texture3, sfTrue);
    sfSprite_setScale(inventory->sprite3, inventory->scale);
    sfSprite_setOrigin(inventory->sprite3, (sfVector2f){278.5, 201});
    return inventory;
}

inv_t *init_inventory(player_t *player)
{
    inv_t *inventory = malloc(sizeof(inv_t));

    inventory->sprite = sfSprite_create();
    inventory->sprite2 = sfSprite_create();
    inventory->sprite3 = sfSprite_create();
    inventory->texture = sfTexture_createFromFile("assets/inventory_1.png",
        NULL);
    inventory->texture2 = sfTexture_createFromFile("assets/inventory_2.png",
        NULL);
    inventory->texture3 = sfTexture_createFromFile("assets/inventory_3.png",
        NULL);
    inventory = content_init_inv(inventory, player);
    inventory = set_texture(inventory);
    inventory->helmet_equiped = 0;
    inventory->hand_equiped = 0;
    inventory->foot_equiped = 0;
    inventory->chest_equiped = 0;
    inventory->frag_equiped = 0;
    return inventory;
}

all_menus_t *init_menus(player_t *player)
{
    all_menus_t *menus = malloc(sizeof(all_menus_t));

    menus->menu = init_menu();
    menus->inventory = init_inventory(player);
    return menus;
}
