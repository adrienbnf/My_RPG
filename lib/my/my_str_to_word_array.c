/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Write a function that splits a string into words.
** Separators will all be non-alphanumeric characters.
** The function returns an array in which each cell contains
** the address of a string (representing a word).
** The last cell must be null to terminate the array
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"


static int is_separator(char c, char *separators)
{
    int i = 0;

    while (separators[i] != '\0') {
        if (c == separators[i])
            return 1;
        i++;
    }
    return 0;
}

int next_arg(char const *str, char *separators, int i)
{
    while (str[i] != '\0' && is_separator(str[i], separators) == 0)
        i++;
    return i;
}

int count_args(char const *str, char *separators)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] != '\0' && is_separator(str[i], separators) == 0) {
            i = next_arg(str, separators, i);
            count++;
        } else
            i++;
    }
    return count;
}

static char *my_strncpy_stwa(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[n - 1] = '\0';
    return dest;
}

static char *my_strdup_stwa(char const *str, char *separators)
{
    int i = 0;
    char *send = NULL;

    while (str[i] != '\0' && is_separator(str[i], separators) == 0) {
        i++;
    }
    send = malloc(i + 1);
    my_strncpy_stwa(send, str, i + 1);
}

char **my_str_to_word_array(char const *str, char *separators)
{
    char **array = malloc(sizeof(char *) * (count_args(str, separators) + 1));
    int i = 0;
    int line = 0;

    while (str[i] != '\0') {
        if (str[i] != '\0' && is_separator(str[i], separators) == 0) {
            array[line] = my_strdup_stwa(str + i, separators);
            i = next_arg(str, separators, i);
            line++;
        } else
            i++;
    }
    array[line] = NULL;
    return array;
}
