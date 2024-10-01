/*
** EPITECH PROJECT, 2024
** cretae plus minus buttons
** File description:
** c
*/

#include "inv.h"

button_t *create_button_mheal_minus(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->pos = (sfVector2f){0, 0};
    button->size = (sfVector2f){9, 10};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = my_strdup("att_plus");
    button->rect = sfRectangleShape_create();
    button->state = 0;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    sfRectangleShape_setOutlineThickness(button->rect, 1.2);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

button_t *create_button_mheal_plus(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->pos = (sfVector2f){0, 0};
    button->size = (sfVector2f){9, 10};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = my_strdup("att_plus");
    button->rect = sfRectangleShape_create();
    button->state = 0;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    sfRectangleShape_setOutlineThickness(button->rect, 1.2);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

button_t *create_button_heal_minus(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->pos = (sfVector2f){0, 0};
    button->size = (sfVector2f){9, 10};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = my_strdup("att_plus");
    button->rect = sfRectangleShape_create();
    button->state = 0;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    sfRectangleShape_setOutlineThickness(button->rect, 1.2);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

button_t *create_button_heal_plus(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->pos = (sfVector2f){0, 0};
    button->size = (sfVector2f){9, 10};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = my_strdup("att_plus");
    button->rect = sfRectangleShape_create();
    button->state = 0;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    sfRectangleShape_setOutlineThickness(button->rect, 1.2);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

button_t *create_button_spd_plus(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->pos = (sfVector2f){0, 0};
    button->size = (sfVector2f){9, 10};
    button->is_clicked = &is_clicked;
    button->is_hover = &is_hover;
    button->name = my_strdup("att_plus");
    button->rect = sfRectangleShape_create();
    button->state = 0;
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
    sfRectangleShape_setOutlineColor(button->rect, sfMagenta);
    sfRectangleShape_setOutlineThickness(button->rect, 1.2);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}
