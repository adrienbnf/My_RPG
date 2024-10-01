/*
** EPITECH PROJECT, 2023
** rev str
** File description:
** reverses a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    int half = len / 2;
    char step;

    while (i <= half) {
        step = str[i];
        str[i] = str[len - i];
        str[len - i] = step;
        i++;
    }
    return (str);
}
