/*
** EPITECH PROJECT, 2023
** get coor
** File description:
** ..
*/
#include "my.h"

int get_y_two(char **tab, int y)
{
    for (int x = 0; tab[y][x] != '\0'; x++) {
        if (tab[y][x] == 'P')
            return y;
    }
    return -1;
}

int get_y(char **tab)
{
    for (int y = 0; tab[y] != NULL; y++) {
        if (get_y_two(tab, y) != -1)
            return get_y_two(tab, y);
    }
    return -84;
}

int get_x_two(char **tab, int y)
{
    for (int x = 0; tab[y][x] != '\0'; x++) {
        if (tab[y][x] == 'P')
            return x;
    }
    return -1;
}

int get_x(char **tab)
{
    for (int y = 0; tab[y] != NULL; y++) {
        if (get_x_two(tab, y) != -1) {
            return get_x_two(tab, y);
        }
    }
    return -84;
}
