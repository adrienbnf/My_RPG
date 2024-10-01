/*
** EPITECH PROJECT, 2024
** delete item
** File description:
** delete item
*/

#include "player.h"
#include "rpg.h"
#include "inv.h"

static void up_all_rect(items_t *current)
{
    items_t *tmp = current;

    while (tmp != NULL) {
        if (tmp->next != NULL) {
            tmp->next->id = tmp->id;
        }
        tmp = tmp->next;
    }
}

static void remove_stats_stuff(items_t *current, player_t *player)
{
    player->stat->attack -= current->stat->attack;
    player->stat->defense -= current->stat->defense;
    player->stat->speed -= current->stat->speed;
    player->stat->health -= current->stat->health;
    player->stat->max_health -= current->stat->max_health;
}

static void desac_stuff(items_t *current, all_menus_t *menus, player_t *player)
{
    if (strcmp(current->class, "helmet") == 0) {
        player->armor[0] = 0;
        menus->inventory->helmet_stuff->str_texture = NULL;
        remove_stats_stuff(current, player);
    }
    if (strcmp(current->class, "chest") == 0) {
        player->armor[1] = 0;
        menus->inventory->chest_stuff->str_texture = NULL;
        remove_stats_stuff(current, player);
    }
    if (strcmp(current->class, "weapon") == 0) {
        menus->inventory->hand_stuff->str_texture = NULL;
        remove_stats_stuff(current, player);
    }
    if (strcmp(current->class, "foot") == 0) {
        player->armor[2] = 0;
        menus->inventory->foot_stuff->str_texture = NULL;
        remove_stats_stuff(current, player);
    }
    naked_sprite_player(player);
}

static void content_del_item(items_t *current, items_t **head,
    all_menus_t *menus, player_t *player)
{
    up_all_rect(current);
    desac_stuff(current, menus, player);
    if (current->prev != NULL)
        current->prev->rect_visible = 1;
    else if (current->next != NULL)
        current->next->rect_visible = 1;
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current->name);
    free(current->stat);
    free(current);
}

void delete_item(items_t **head, int id, all_menus_t *menus, player_t *player)
{
    items_t *current = *head;

    printf("in delete func\n");
    while (current != NULL) {
        if (current->id == id) {
            content_del_item(current, head, menus, player);
            return;
        }
        current = current->next;
    }
}
