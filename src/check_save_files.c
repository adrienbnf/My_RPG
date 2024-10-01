/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** check_save_files
*/

#include "rpg.h"

static char *load_save_file_in_str(char *path)
{
    struct stat sb;
    int fd = 0;
    char *buffer = NULL;

    stat(path, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    buffer[sb.st_size] = '\0';
    fd = open(path, O_RDONLY);
    read(fd, buffer, sb.st_size);
    close(fd);
    return buffer;
}

static int check_coord_save(char *buffer)
{
    char **array = my_str_to_word_array(buffer, "\n ");

    if (array_len(array) != 2)
        return 0;
    return 1;
}

static int check_inventory_save(char *buffer)
{
    return 1;
}

static int check_items_save(char *buffer)
{
    return 1;
}

static int check_stat_save(char *buffer)
{
    char **array = my_str_to_word_array(buffer, "\n ");

    if (array_len(array) != 9)
        return 0;
    return 1;
}

int save_files_correct(void)
{
    char *path_files[] = {"src/save/coord.txt", "src/save/inventory.txt",
    "src/save/items.txt", "src/save/stat.txt", NULL};
    int (*check_func[])(char *) = {&check_coord_save, &check_inventory_save,
    &check_items_save, &check_stat_save};
    int fd = 0;
    char *buffer = NULL;

    for (int i = 0; path_files[i] != NULL; ++i){
        fd = open(path_files[i], O_RDONLY);
        if (fd == -1)
            return 0;
        close(fd);
        buffer = load_save_file_in_str(path_files[i]);
        if (check_func[i](buffer) == 0)
            return 0;
    }
    return 1;
}
