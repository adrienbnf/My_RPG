/*
** EPITECH PROJECT, 2024
** event h
** File description:
** event h
*/

#ifndef EVENT_H
    #define EVENT_H
    #include "inv.h"
    #include "player.h"
    #include "rpg.h"

void handle_event(video_t *, all_menus_t *, player_t *);
void save(player_t *player);
void verif_fragments(video_t *video, player_t *player, all_menus_t *menus);
void keyboard_fragment(video_t *video, sfEvent event);

#endif /* !EVENT_H */
