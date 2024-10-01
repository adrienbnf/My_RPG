/*
** EPITECH PROJECT, 2023
** muy strncmp
** File description:
** Reproduce the behavior of the strncmp function.
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int b = my_strlen(s1);
    int c = my_strlen(s2);

    if (b > c) {
        b = c;
    }
    while (s1[i] == s2[i] && i < b && i < n) {
        i++;
    }
    if (i == n) {
        return 0;
    } else {
        return s1[i] - s2[i];
    }
}
