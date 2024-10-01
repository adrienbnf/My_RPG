/*
** EPITECH PROJECT, 2023
** my strdup
** File description:
** Write a function that allocates memory and copies
** the string given as argument in it
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *send;

    send = malloc(sizeof(char) * my_strlen(src) + 1);
    send = my_strcpy(send, src);
    return send;
}

char **my_arraydup(char **src)
{
    int l = my_arrlen(src);
    char **send = malloc(sizeof(char *) * (l + 1));

    for (int i = 0; src[i]; i++) {
        send[i] = my_strdup(src[i]);
    }
    send[l] = NULL;
    return send;
}
