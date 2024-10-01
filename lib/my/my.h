/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/


#ifndef MY_H
    #define MY_H
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stddef.h>
char **my_arraydup(char **src);
int my_ararraylen(char ***a);
int my_show_word_array(char *const *tab);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
int my_arrlen(char **a);
char *my_input(char *print);
char **my_str_to_word_array(char const *str, char *separator);
int my_abs(int nb);
int how_many_digits(long long unsigned nb);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_putchar(int c);
int my_printf(char const *s, ...);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char const *src);
char *my_revstr(char *str);
#endif
