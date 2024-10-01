/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** error_handling
*/


#include "inv.h"
#include "player.h"
#include "rpg.h"
#include "ennemy.h"
#include "colision.h"
#include "path_assets.h"
#include "entities.h"
#include "event.h"
#include "my_menu.h"

int get_size(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        return 1;
    }
    return sb.st_size;
}

char *get_buffer(int sizee, int fd)
{
    int size = 0;
    char *buffer = malloc(sizeof(char) * (sizee + 1));

    while (size == 0) {
        size = read(fd, buffer, sizee);
    }
    buffer[sizee] = '\0';
    return buffer;
}

int open_all(void)
{
    int fd = open("./assets.txt", O_RDONLY);
    int size = 0;
    int tmp;
    char **buffer = NULL;

    if (fd == -1) {
        exit(84);
    }
    size = get_size("assets.txt");
    buffer = my_str_to_word_array(get_buffer(size, fd), "\n");
    close(fd);
    for (int i = 0; buffer[i]; i++) {
        tmp = open(buffer[i], O_RDONLY);
        if (tmp == -1) {
            printf("%s doesn't exit\n", buffer[i]);
            exit(84);
        }
        close(tmp);
    }
    return 0;
}
