/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** menu_event
*/
#include "rpg.h"
#include "my_menu.h"
#include "event.h"

static void button_event_two(video_t *video, menu_t *menu, sfEvent event,
    sfVector2u s)
{
    if (event.type == sfEvtMouseButtonPressed && menu->quit_button->
    is_hover(menu->quit_button, &event.mouseButton, menu->pos, (float)s.x)) {
        main_menu_scene(video);
        printf("QUIT\n");
    }
}

static void button_event(video_t *video, struct menu_s *menu, sfEvent event,
    player_t *player)
{
    sfVector2u s = sfRenderWindow_getSize(video->win);

    keys_gestion(player, event, menu, video);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        menu->SB->is_hover(menu->sound_bar,
        &event.mouseMove, menu->pos, (float)s.x);
    if (event.type == sfEvtMouseButtonPressed)
        menu->reso_bar->is_hover(menu->reso_bar,
        &event.mouseButton, menu->pos, (float)s.x);
    if (event.type == sfEvtMouseButtonPressed && menu->save_button->
    is_hover(menu->save_button, &event.mouseButton, menu->pos, (float)s.x)) {
        printf("SAVE\n");
        save(player);
    }
    if (event.type == sfEvtMouseButtonPressed && menu->exit_button->
    is_hover(menu->exit_button, &event.mouseButton, menu->pos, (float)s.x)) {
        menu->open = 0;
        printf("EXIT\n");
    }
    button_event_two(video, menu, event, s);
}

static void menu_gestion(menu_t *menu)
{
    if (menu->open)
        menu->open = 0;
    else
        menu->open = 1;
    return;
}

static void change_music_bool(menu_t *menu)
{
    if (menu->sound_bar->lock_music == sfTrue)
        menu->sound_bar->lock_music = sfFalse;
    else
        menu->sound_bar->lock_music = sfTrue;
}

void menu_event(video_t *video, menu_t *menu, sfEvent event, player_t *player)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        menu_gestion(menu);
    if (menu->open)
        button_event(video, menu, event, player);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM) {
        change_music_bool(menu);
    }
}
