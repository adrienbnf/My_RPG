/*
** EPITECH PROJECT, 2024
** event
** File description:
** vent
*/

#include "event.h"
#include "my_menu.h"


void keys_gestion(player_t *p, sfEvent event, menu_t *menu, video_t *v)
{
    sfVector2u s = sfRenderWindow_getSize(v->win);

    if (event.type == sfEvtMouseButtonPressed && menu->azerty_button->
    is_hover(menu->azerty_button, &event.mouseButton, menu->pos, (float)s.x)) {
        p->keys = (keys_t){sfKeyZ, sfKeyS, sfKeyQ, sfKeyD};
        printf("AZERTY\n");
    }
    if (event.type == sfEvtMouseButtonPressed && menu->qwerty_button->
    is_hover(menu->qwerty_button, &event.mouseButton, menu->pos, (float)s.x)) {
        p->keys = (keys_t){sfKeyW, sfKeyS, sfKeyA, sfKeyD};
        printf("QWERTY\n");
    }
}

static void put_fragment_stuff(player_t *player,
    all_menus_t *menus)
{
    if (player->frag_count == 1) {
        menus->inventory->frag_stuff->str_texture = stuff_path[FRAG1];
    }
    if (player->frag_count == 2) {
        menus->inventory->frag_stuff->str_texture = stuff_path[FRAG2];
    }
    if (player->frag_count == 3) {
        menus->inventory->frag_stuff->str_texture = stuff_path[FRAG3];
    }
}

void handle_event(video_t *video, all_menus_t *menus, player_t *player)
{
    sfEvent event;
    int i = 0;

    while (sfRenderWindow_pollEvent(video->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(video->win);
        events_inv(video, event, menus, player);
        menu_event(video, menus->menu, event, player);
        verif_fragments(video, player, menus);
        put_fragment_stuff(player, menus);
    }
}
