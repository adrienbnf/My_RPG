/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** Functions to load a file in an array
*/

#include "../include/rpg.h"

char **load_array_from_file(char *path)
{
    struct stat sb;
    char *buffer = NULL;
    int fd = 0;
    char **array = NULL;

    stat(path, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    buffer[sb.st_size] = '\0';
    fd = open(path, O_RDONLY | O_CREAT);
    if (fd == -1)
        return NULL;
    read(fd, buffer, sb.st_size);
    array = my_str_to_word_array(buffer, "\n");
    close(fd);
    free(buffer);
    return array;
}
