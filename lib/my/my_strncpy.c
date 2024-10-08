/*
** EPITECH PROJECT, 2023
** my strncpy
** File description:
** Write a function that copies n characters from a string into another.
** The destination string will already have enough
** memory to contain n characters.
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[n - 1] = '\0';
    return dest;
}
