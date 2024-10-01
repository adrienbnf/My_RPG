/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** main_menu
*/

#include "path_assets.h"
#include "my_menu.h"

static logo_t *init_logo_mm(void)
{
    logo_t *logo = malloc(sizeof(logo_t));

    logo->texture = sfTexture_createFromFile(path_assets[LOGO], NULL);
    logo->sprite = sfSprite_create();
    logo->scale = (sfVector2f){0.1, 0.1};
    logo->t_anim = 0;
    logo->scale_up = sfTrue;
    sfSprite_setTexture(logo->sprite, logo->texture, sfTrue);
    sfSprite_setPosition(logo->sprite, (sfVector2f){600.0, 500.0});
    sfSprite_setOrigin(logo->sprite, (sfVector2f){333, 188});
    sfSprite_setScale(logo->sprite, logo->scale);
    return logo;
}

static void animate_mm_button_clicked(mm_buttons_t *button, sfClock *clock)
{
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (seconds - button->t_anim > 0.10){
        button->t_anim = seconds;
        button->cursor_sprite.left += W_MM_BUTTON;
        if (button->cursor_sprite.left >= MAX_SPRITE_MM_BUTTON){
            button->quit_menu = 1;
            button->clicked = 0;
            button->cursor_sprite.left = 0;
            return;
        }
        sfSprite_setTextureRect(button->sprite, button->cursor_sprite);
    }
}

static void click_main_menu_handling(mm_buttons_t *button, sfClock *clock)
{
    if (button->hovered && sfMouse_isButtonPressed(sfMouseLeft)){
        button->clicked = 1;
    }
    if (button->clicked)
        animate_mm_button_clicked(button, clock);
}

static void hover_main_menu_handling(mm_buttons_t *button, sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);

    if (mouse.x > button->pos.x && mouse.x < button->pos.x + W_MM_BUTTON * 4 &&
        mouse.y > button->pos.y && mouse.y < button->pos.y + H_MM_BUTTON * 4){
        sfSprite_setScale(button->sprite, (sfVector2f){5.0, 5.0});
        button->hovered = 1;
    } else {
        sfSprite_setScale(button->sprite, (sfVector2f){4.0, 4.0});
        button->hovered = 0;
    }
}

static int handle_event_on_main_menu(video_t *video)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(video->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(video->win);
    }
}

static void launch_button_action(mm_buttons_t *button, video_t *video)
{
    player_t *player = NULL;

    if (button->type == NEW_GAME){
        printf("hello");
        player = init_player_default();
        map_one(player, video);
    }
    if (button->type == CONTINUE){
        if (save_files_correct()) {
            player = init_player_saved();
        } else
            player = init_player_default();
        map_one(player, video);
    }
    if (button->type == QUIT_MM)
        sfRenderWindow_close(video->win);
}

static int quit_main_menu(mm_buttons_t **buttons, video_t *video)
{
    for (int i = 0; buttons[i] != NULL; ++i)
        if (buttons[i]->quit_menu == 1){
            launch_button_action(buttons[i], video);
            return 1;
        }
    return 0;
}

int main_menu_scene(video_t *video)
{
    main_menu_t *mm = init_main_menu();
    sfVector2u win_size = sfRenderWindow_getSize(video->win);
    logo_t *logo = init_logo_mm();

    sfRenderWindow_setView(video->win,
    sfView_createFromRect((sfFloatRect){0, 0, win_size.x, win_size.y}));
    while (sfRenderWindow_isOpen(video->win)
    && !quit_main_menu(mm->buttons, video)){
        handle_event_on_main_menu(video);
        sfRenderWindow_drawSprite(video->win, mm->bg.sprite, NULL);
        animate_logo(logo, video, video->clock);
        for (int i = 0; mm->buttons[i] != NULL; ++i){
            hover_main_menu_handling(mm->buttons[i], video->win);
            click_main_menu_handling(mm->buttons[i], video->clock);
            sfRenderWindow_drawSprite(video->win, mm->buttons[i]->sprite,
            NULL);
        }
        sfRenderWindow_display(video->win);
    }
    return 0;
}
