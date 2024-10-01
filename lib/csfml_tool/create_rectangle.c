/*
** EPITECH PROJECT, 2024
** CSFML
** File description:
** create_rectangle
*/

#include "csfml_tool.h"

sfRectangleShape *create_rectangle(sfVector2f pos, sfVector2f size,
    int show_border, sfColor color)
{
    sfRectangleShape *rect = NULL;

    rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    if (show_border)
        sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, color);
    return rect;
}
