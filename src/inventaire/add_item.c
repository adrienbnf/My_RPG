/*
** EPITECH PROJECT, 2024
** add_item
** File description:
** add item
*/

#include "inv.h"
#include "rpg.h"

static char *content_get_item_value(char **tmp, int i, char *value)
{
    for (int j = 0; tmp[j]; j++) {
        if (strncmp(tmp[j], value, strlen(value)) == 0) {
            return strdup(tmp[j] + strlen(value));
        }
    }
}

char *get_item_value(char *name, char *value)
{
    struct stat sb;
    char *buffer = NULL;
    int fd = 0;
    char **arr = NULL;
    char **tmp = NULL;

    lstat("src/save/items.txt", &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    buffer[sb.st_size] = '\0';
    fd = open("src/save/items.txt", O_RDONLY | O_CREAT);
    read(fd, buffer, sb.st_size);
    arr = my_str_to_word_array(buffer, "\n");
    for (int i = 0; arr[i]; i++) {
        if (strncmp(arr[i], name, strlen(name)) == 0) {
            tmp = my_str_to_word_array(arr[i], ";");
            return content_get_item_value(tmp, i, value);
        }
    }
}

static sfRectangleShape *init_rect_item(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfColor color = {255, 206, 130, 255};

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, color);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){35, 7});
    return rect;
}

items_t *create_node(char *name, int i)
{
    items_t *element = malloc(sizeof(items_t));

    element->name = strdup(name);
    element->class = get_item_value(name, "CLASS");
    element->equiped = 0;
    element->id = i;
    element->id_description = my_getnbr(get_item_value(name, "ID"));
    element->rect_visible = 0;
    if (i == 0)
        element->rect_visible = 1;
    element->rect = init_rect_item();
    element->stat = malloc(sizeof(stat_t));
    element->stat->attack = my_getnbr(get_item_value(name, "ATTACK"));
    element->stat->defense = my_getnbr(get_item_value(name, "DEFENSE"));
    element->stat->health = my_getnbr(get_item_value(name, "HEALTH"));
    element->stat->speed = my_getnbr(get_item_value(name, "SPEED"));
    element->stat->max_health = my_getnbr(get_item_value(name, "MAX_HEALTH"));
    element->next = NULL;
    element->prev = NULL;
    return element;
}

void add_item(items_t **head, char *name, int i)
{
    items_t *newNode = create_node(name, i);
    items_t *temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
