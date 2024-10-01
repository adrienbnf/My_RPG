/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** collision_getion
*/

#include "colision.h"
#include "rpg.h"

static char *create_buffer(char const *path)
{
    struct stat map_file;
    int fd = open(path, O_RDONLY);
    char *buffer;

    stat(path, &map_file);
    buffer = malloc(sizeof(char) * (map_file.st_size + 1));
    read(fd, buffer, map_file.st_size);
    buffer[map_file.st_size] = '\0';
    close(fd);
    return buffer;
}

static sfVector2f find_player(char **tab)
{
    sfVector2f pos;

    pos.x = (float)get_x(tab);
    pos.y = (float)get_y(tab);
    return pos;
}

player_t *init_colision(player_t *player, char const *path)
{
    player->colision = malloc(sizeof(colision_t));
    player->colision->map = my_str_to_word_array(create_buffer(path), "\n");
    if (player->colision->map == NULL)
        exit(84);
    player->colision->map_copy = my_arraydup(player->colision->map);
    player->colision->pos_player = (sfVector2f){player->pos.x / 8,
    player->pos.y / 8};
    return player;
}
