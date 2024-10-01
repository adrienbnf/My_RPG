/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** Function to normalize a vector
*/

#include "rpg.h"

void normalize(sfVector2f *vector)
{
    float length = sqrt(vector->x * vector->x + vector->y * vector->y);

    if (length != 0){
        vector->x /= length;
        vector->y /= length;
    }
}
