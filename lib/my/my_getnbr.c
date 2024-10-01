/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_get_nbr
*/

#include "../../include/rpg.h"

static int content(char const *str, int i, int *nb, int *isneg)
{
    int stop = 0;

    if (str[i] >= '0' && str[i] <= '9') {
        if (i < 0 && str[i - 1] == '-')
            *isneg = *isneg * -1;
        *nb = *nb * 10;
        *nb = *nb + str[i] - '0';
        if (str[i + 1] < '0' || str[i + 1] > '9')
            stop = 1;
    }
    return stop;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int stop = 0;
    int isneg = 1;

    nb = 0;
    i = 0;
    while (str[i] != '\0') {
        stop = content(str, i, &nb, &isneg);
        if (stop == 1)
            break;
        i++;
    }
    return (nb * isneg);
}
