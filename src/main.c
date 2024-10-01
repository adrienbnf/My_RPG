/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** Main function of the project
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

static void init_shaders(video_t *video)
{
    video->shader = sfShader_createFromFile(NULL, NULL,
        "src/fragment_shader.frag");
    video->isGray = sfTrue;
    video->restoreSomeColor = sfFalse;
    video->restoreMoreColor = sfFalse;
    video->restoreFullColor = sfFalse;
    sfShader_setBoolUniform(video->shader, "isGray", video->isGray);
    sfShader_setBoolUniform(video->shader, "restoreSomeColor",
        video->restoreSomeColor);
    sfShader_setBoolUniform(video->shader, "restoreMoreColor",
        video->restoreMoreColor);
    sfShader_setBoolUniform(video->shader, "restoreFullColor",
        video->restoreFullColor);
    video->states = (sfRenderStates){sfBlendAlpha, sfTransform_Identity, NULL,
        video->shader};
}

static video_t *init_video(void)
{
    video_t *video = malloc(sizeof(video_t));

    video->back_p = sfTexture_createFromFile(path_assets[MAP_1_OUTSIDE_1],
    NULL);
    video->back_player = sfSprite_create();
    sfSprite_setTexture(video->back_player, video->back_p, sfFalse);
    video->front_p = sfTexture_createFromFile(path_assets[MAP_1_OUTSIDE_2],
    NULL);
    video->front_player = sfSprite_create();
    sfSprite_setTexture(video->front_player, video->front_p, sfFalse);
    video->win = init_window();
    video->clock = sfClock_create();
    video->music = sfMusic_createFromFile("./assets/music/Japanese Anime "
    "Music - Ancient Village.ogg");
    sfMusic_setLoop(video->music, sfTrue);
    sfMusic_setVolume(video->music, 20);
    init_shaders(video);
    return video;
}

static void draw_chests(video_t *v, chest_t *chest, player_t *p,
    all_menus_t *menus)
{
    chest_t *tmp = chest;
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(p->vision);
    sfFloatRect rect2;
    sfFloatRect intersection;

    while (tmp != NULL){
        rect2 = sfRectangleShape_getGlobalBounds(tmp->hit_box);
        if (sfFloatRect_intersects(&rect1, &rect2, &intersection)) {
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfRenderWindow_drawSprite(v->win, tmp->sprite, NULL);
            sfRenderWindow_drawRectangleShape(v->win, tmp->hit_box, NULL);
        }
        tmp = tmp->next;
    }
}

static void draw_ennemy(video_t *video, ennemy_t *ennemy, player_t *p,
    all_menus_t *menus)
{
    ennemy_t *tmp = ennemy;
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(p->vision);
    sfFloatRect rect2;
    sfFloatRect intersection;

    while (tmp != NULL){
        rect2 = sfRectangleShape_getGlobalBounds(tmp->hit_box);
        if (sfFloatRect_intersects(&rect1, &rect2, &intersection)) {
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfRenderWindow_drawSprite(video->win, tmp->sprite, NULL);
        sfRenderWindow_drawRectangleShape(video->win, tmp->hit_box, NULL);
        sfRenderWindow_drawRectangleShape(video->win, tmp->vision, NULL);
        sfMusic_setVolume(tmp->damage, menus->menu->sound_bar->vol);
        }
        tmp = tmp->next;
    }
}

static void draw_pnj(video_t *video, pnj_t *pnj, player_t *p,
    all_menus_t *menus)
{
    pnj_t *tmp = pnj;
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(p->vision);
    sfFloatRect rect2;
    sfFloatRect intersection;

    while (tmp != NULL) {
        rect2 = sfRectangleShape_getGlobalBounds(tmp->hit_box);
        if (sfFloatRect_intersects(&rect1, &rect2, &intersection)) {
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfRenderWindow_drawSprite(video->win, tmp->sprite, NULL);
            sfRenderWindow_drawRectangleShape(video->win, tmp->hit_box, NULL);
            sfRenderWindow_drawRectangleShape(video->win, tmp->vision, NULL);
        }
        tmp = tmp->next;
    }
}

void draw_gestion(video_t *video, player_t *player, entities_t *entities,
    all_menus_t *menus)
{
    sound_gestion(video, menus, player);
    sfRenderWindow_clear(video->win, sfBlack);
    sfRenderWindow_drawSprite(video->win, video->back_player, &video->states);
    draw_ennemy(video, entities->ennemies, player, menus);
    draw_pnj(video, entities->pnj, player, menus);
    draw_chests(video, entities->chest, player, menus);
    sfRenderWindow_drawRectangleShape(video->win, player->hitbox, NULL);
    sfRenderWindow_drawRectangleShape(video->win, player->atk_hitbox, NULL);
    sfRenderWindow_drawSprite(video->win, player->sprite, NULL);
    sfRenderWindow_drawRectangleShape(video->win, player->vision, NULL);
    sfRenderWindow_drawSprite(video->win, video->front_player, &video->states);
    update_and_display_victory(player, video);
}

void map_one(player_t *player, video_t *video)
{
    entities_t *entities = init_entities();
    all_menus_t *menus = init_menus(player);

    player = init_colision(player, path_assets[MAP_1_COLISION]);
    while (sfRenderWindow_isOpen(video->win)){
        draw_gestion(video, player, entities, menus);
        if (menus->menu->open == 0) {
            player_loop(player, video, entities->ennemies);
            entities_loop(entities, video, player);
        } else
            place_menu(menus->menu, player, video);
        if (player->stat->health <= 0){
            destroy_map1(entities, menus);
            return game_over_animation(player, video, video->clock);
        }
        handle_event(video, menus, player);
        display_menus(menus, player, video);
        sfRenderWindow_display(video->win);
    }
    destroy_map1(entities, menus);
}

int main(void)
{
    video_t *video = NULL;

    open_all();
    video = init_video();
    intro_loop(video);
    sfMusic_play(video->music);
    main_menu_scene(video);
    destroy_video(video);
}
