/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** rect_are_colliding
*/

#include "csfml_tool.h"

int rect_are_colliding(sfRectangleShape *rect1, sfRectangleShape *rect2)
{
    sfVector2f size1 = sfRectangleShape_getSize(rect1);
    sfVector2f size2 = sfRectangleShape_getSize(rect2);
    sfVector2f pos1 = sfRectangleShape_getPosition(rect1);
    sfVector2f pos2 = sfRectangleShape_getPosition(rect2);

    if (pos1.y <= pos2.y + size2.y && pos1.y + size1.y >= pos2.y
        && pos1.x <= pos2.x + size2.x && pos1.x + size1.x >= pos2.x)
        return 1;
    return 0;
}
