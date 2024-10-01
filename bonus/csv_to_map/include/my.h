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
    #include <sys/stat.h>
    #include <stddef.h>
    #include <string.h>


char **my_str_to_word_array(char const *str, char *separators);
#endif
