/*
** EPITECH PROJECT, 2024
** init items
** File description:
** init items
*/

#include "path_assets.h"
#include "player.h"
#include "inv.h"
#include "rpg.h"

items_t *init_items(void)
{
    char **inv = load_array_from_file("src/save/inventory.txt");
    items_t *item = NULL;

    if (inv != NULL) {
        for (int i = 0; inv[i]; i++) {
            add_item(&item, inv[i], i);
        }
    }
    return item;
}

char *init_item_list_str(items_t *items)
{
    char *str = NULL;
    char *s = NULL;
    items_t *tmp = items;

    if (items != NULL) {
        str = my_strcat("\n", items->name);
        tmp = tmp->next;
    }
    for (; tmp != NULL; tmp = tmp->next) {
        s = my_strcat("\n", tmp->name);
        str = my_strcat(str, s);
    }
    free(s);
    return str;
}

char *init_item_description_str(items_t *items)
{
    char *str = NULL;
    items_t *tmp = items;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->rect_visible == 1) {
            str = descriptions[tmp->id_description];
            break;
        }
    }
    return str;
}

sfText *init_item_list(player_t *player)
{
    sfFont* font = sfFont_createFromFile(path_assets[FONT]);
    sfText* text = sfText_create();
    sfColor color = {92, 64, 51, 255};

    sfText_setString(text, init_item_list_str(player->items));
    sfText_setFont(text, font);
    sfText_setScale(text, (sfVector2f){0.20, 0.20});
    sfText_setLineSpacing(text, 1.3);
    sfText_setColor(text, color);
    sfText_setPosition(text, (sfVector2f){0, 0});
    return text;
}

sfText *init_item_description(void)
{
    sfFont* font = sfFont_createFromFile(path_assets[FONT]);
    sfText* text = sfText_create();
    sfColor color = {92, 64, 51, 255};

    sfText_setString(text, "caca");
    sfText_setFont(text, font);
    sfText_setScale(text, (sfVector2f){0.20, 0.20});
    sfText_setLineSpacing(text, 1.3);
    sfText_setColor(text, color);
    sfText_setPosition(text, (sfVector2f){0, 0});
    return text;
}
