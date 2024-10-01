/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** len_items
*/

#include "player.h"

int len_items(items_t *items)
{
    items_t *tmp = items;
    int count = 0;

    while (tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}
