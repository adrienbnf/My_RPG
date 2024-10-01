/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** Function that return the lenght of an array
*/

#include "rpg.h"

int array_len(char **array)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; ++i){
        count++;
    }
    return count;
}
