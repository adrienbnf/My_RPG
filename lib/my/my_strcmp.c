/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** Reproduce the behavior of the strcmp function
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int b = my_strlen(s1);
    int c = my_strlen(s2);

    if (b != c) {
        return -1;
    }
    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    if (s1[i] < s2[i]) {
        return s1[i] - s2[i];
    } else if (s2[i] < s1[i]) {
        return s1[i] - s2[i];
    }
    return 0;
}
