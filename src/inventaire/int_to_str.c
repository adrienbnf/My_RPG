/*
** EPITECH PROJECT, 2024
** int to tr
** File description:
** int to str
*/

#include "../include/rpg.h"

static int len_nbr(int nb)
{
    int count = 1;

    while (nb >= 10) {
        count++;
        nb = nb / 10;
    }
    return count;
}

char *int_to_str(int score)
{
    int len = len_nbr(score);
    char *str = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int digit = score;

    while (i < len) {
        str[i] = 48 + digit % 10;
        digit = digit / 10;
        i++;
    }
    str[i] = '\0';
    return my_revstr(str);
}
