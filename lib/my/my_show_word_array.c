/*
** EPITECH PROJECT, 2023
** my show word array
** File description:
** dispaly a array 2d
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        printf("%s\n", tab[i]);
        i++;
    }
}
