/*
** EPITECH PROJECT, 2024
** save
** File description:
** save
*/

#include "rpg.h"
#include "event.h"

static char *make_inv_str(player_t *player)
{
    char *inv = NULL;
    items_t *tmp = player->items;

    if (tmp != NULL) {
        inv = my_strcat(tmp->name, "\n");
        tmp = tmp->next;
    }
    while (tmp != NULL) {
        inv = my_strcat(inv, tmp->name);
        inv = my_strcat(inv, "\n");
        tmp = tmp->next;
    }
    return inv;
}

static char *add_frag_count(char *stat, player_t *player)
{
    stat = my_strcat(stat, "frag_count=");
    stat = my_strcat(stat, int_to_str(player->frag_count));
    stat = my_strcat(stat, "\n");
    return stat;
}

static char *add_xp_str(char *stat, player_t *player)
{
    stat = my_strcat(stat, "xp=");
    stat = my_strcat(stat, int_to_str(player->xp->xp));
    stat = my_strcat(stat, "\n");
    stat = my_strcat(stat, "level=");
    stat = my_strcat(stat, int_to_str(player->xp->level));
    stat = my_strcat(stat, "\n");
    stat = my_strcat(stat, "credit=");
    stat = my_strcat(stat, int_to_str(player->xp->credit));
    stat = my_strcat(stat, "\n");
    stat = add_frag_count(stat, player);
    return stat;
}

static char *make_stat_str(player_t *player)
{
    char *stat = my_strcat("attack=", int_to_str(player->stat->attack));

    stat = my_strcat(stat, "\n");
    stat = my_strcat(stat, "defense=");
    stat = my_strcat(stat, int_to_str(player->stat->defense));
    stat = my_strcat(stat, "\n");
    stat = my_strcat(stat, "health=");
    stat = my_strcat(stat, int_to_str(player->stat->health));
    stat = my_strcat(stat, "\n");
    stat = my_strcat(stat, "max_health=");
    stat = my_strcat(stat, int_to_str(player->stat->max_health));
    stat = my_strcat(stat, "\n");
    stat = my_strcat(stat, "speed=");
    stat = my_strcat(stat, int_to_str(player->stat->speed));
    stat = my_strcat(stat, "\n");
    stat = add_xp_str(stat, player);
    return stat;
}

static char *make_coord_str(player_t *player)
{
    char *coord = my_strcat(int_to_str(sfSprite_getPosition(player->sprite).x)
        , "\n");

    coord = my_strcat(coord,
        int_to_str(sfSprite_getPosition(player->sprite).y));
    return coord;
}

void save(player_t *player)
{
    FILE *fd_coord = fopen("src/save/coord.txt", "w");
    FILE *fd_stat = fopen("src/save/stat.txt", "w");
    FILE *fd_inv = fopen("src/save/inventory.txt", "w");
    char *coords = make_coord_str(player);
    char *stat = make_stat_str(player);
    char *inventory = make_inv_str(player);

    if (coords != NULL)
        fprintf(fd_coord, "%s", coords);
    if (stat != NULL)
        fprintf(fd_stat, "%s", stat);
    if (inventory != NULL)
        fprintf(fd_inv, "%s", inventory);
    fclose(fd_coord);
    fclose(fd_stat);
    fclose(fd_inv);
}
