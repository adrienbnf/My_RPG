/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** init_main_menu
*/

#include "path_assets.h"
#include "my_menu.h"

mm_buttons_t *add_button_main_menu(float x, float y, int type)
{
    mm_buttons_t *button = malloc(sizeof(mm_buttons_t));

    button->cursor_sprite = (sfIntRect){0, 0, W_MM_BUTTON,
    H_MM_BUTTON};
    button->type = type;
    button->pos = (sfVector2f){x, y};
    button->texture =
    sfTexture_createFromFile(path_assets[MAIN_MENU_BUTT + type], NULL);
    button->sprite = sfSprite_create();
    sfSprite_setScale(button->sprite, (sfVector2f){4.0, 4.0});
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->cursor_sprite);
    button->t_anim = 0;
    button->quit_menu = 0;
    button->clicked = 0;
    button->hovered = 0;
    return button;
}

main_menu_t *init_main_menu(void)
{
    main_menu_t *mm = malloc(sizeof(main_menu_t));

    mm->bg.texture = sfTexture_createFromFile(path_assets[MAIN_MENU_BG], NULL);
    mm->bg.sprite = sfSprite_create();
    sfSprite_setScale(mm->bg.sprite, (sfVector2f){1.8, 1.8});
    sfSprite_setTexture(mm->bg.sprite, mm->bg.texture, sfTrue);
    mm->buttons = malloc(sizeof(mm_buttons_t *) * (NB_BUTTON_MM + 1));
    mm->buttons[0] = add_button_main_menu(1400.0, 100, NEW_GAME);
    mm->buttons[1] = add_button_main_menu(1400.0, 400, CONTINUE);
    mm->buttons[2] = add_button_main_menu(1400.0, 700, QUIT_MM);
    mm->buttons[NB_BUTTON_MM] = NULL;
    return mm;
}
