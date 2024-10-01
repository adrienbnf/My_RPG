/*
** EPITECH PROJECT, 2023
** my strcpy
** File description:
** Write a function that copies a string into another.
** The destination string will already have enough memory
** to copy the source string.
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(src);

    while (i < len) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
