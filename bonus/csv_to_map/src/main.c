/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** ..
*/
#define MAX_LINES 1000

#include "my.h"

char **get_line(FILE *map)
{
    char **line_file = malloc(sizeof(char *) * MAX_LINES);
    int i = 0;
    size_t len = 0;
    size_t line_len = 0;

    line_file[i] = NULL;
    while (i < MAX_LINES && getline(&line_file[i], &len, map) != -1) {
        line_len = strlen(line_file[i]);
        if (line_len > 0 && line_file[i][line_len - 1] == '\n')
            line_file[i][line_len - 1] = '\0';
        i++;
        line_file[i] = NULL;
    }
    line_file[i] = NULL;
    return line_file;
}

char **format_line(char **line)
{
    for (int i = 0; line[i]; i++) {
        char **l_a = my_str_to_word_array(line[i], ",");
        for (int b = 0; l_a[b]; b++) {
            if (strcmp(l_a[b], "-1") == 0)
                l_a[b] = "O";
            else
                l_a[b] = "#";
        }
        char *str = malloc(sizeof(char) * 1000);
        str[0] = '\0';
        for (int b = 0; l_a[b]; b++) {
            str = strcat(str, l_a[b]);
        }
        line[i] = str;
    }
    return line;
}

void write_line(char **line, char *path)
{
    char *tmp = strdup(path);
    int map = open(strcat(tmp, ".txt"), O_CREAT | O_RDWR);
    mode_t nouveau_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    chmod(tmp, nouveau_mode);
    for (int i = 0; line[i]; i++) {
        write(map, line[i], strlen(line[i]));
        write(map, "\n", 1);
    }
    map = open(strcat(path, "_more_graphic.txt"), O_CREAT | O_RDWR);
    chmod(path, nouveau_mode);
    for (int i = 0; line[i]; i++) {
        for (int b = 0; line[i][b] != '\0'; b++) {
            if (line[i][b] == '#')
                printf("\033[31;01m%c \033[00m", line[i][b]);
            else
                printf("\033[36;01m%c \033[00m", line[i][b]);
            write(map, &line[i][b], 1);
            write(map, " ", 1);
        }
        printf("\n");
        write(map, "\n", 1);
    }
}
int main(int ac, char **av)
{
    if (ac != 3)
        return  84;
    FILE *map = fopen(av[1], "r");
    if (map == NULL)
        return 84;
    char **line = get_line(map);
    fclose(map);
    line = format_line(line);
    write_line(line, av[2]);
    return 0;
}
