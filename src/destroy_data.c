/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** destroy_data
*/

#include "my_menu.h"
#include "inv.h"
#include "player.h"

void destroy_button(button_t *button)
{
    free(button->name);
    sfRectangleShape_destroy(button->rect);
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
    free(button->str_texture);
    free(button);
}

void destroy_all_menus(all_menus_t *menus)
{
    sfText_destroy(menus->inventory->item_description);
    sfTexture_destroy(menus->inventory->texture);
    sfTexture_destroy(menus->inventory->texture2);
    sfTexture_destroy(menus->inventory->texture3);
    sfSprite_destroy(menus->inventory->sprite);
    sfSprite_destroy(menus->inventory->sprite2);
    sfSprite_destroy(menus->inventory->sprite3);
    free(menus->inventory);
    free(menus->menu);
}

static void destroy_text_box(text_box_t *t_box)
{
    sfClock_destroy(t_box->clock);
    sfTexture_destroy(t_box->texture);
    sfSprite_destroy(t_box->sprite);
    sfText_destroy(t_box->text);
    sfFont_destroy(t_box->font);
    for (int i = 0; t_box->comment[i] != NULL; i++)
        free(t_box->comment[i]);
    free(t_box->comment);
}

static void destroy_ennemies(ennemy_t *ennemy)
{
    ennemy_t *tmp = ennemy;
    ennemy_t *stock = NULL;

    while (tmp != NULL){
        sfRectangleShape_destroy(tmp->hit_box);
        sfSprite_destroy(tmp->sprite);
        sfTexture_destroy(tmp->texture);
        sfRectangleShape_destroy(tmp->vision);
        free(tmp->stat);
        stock = tmp;
        tmp = tmp->next;
        free(stock);
    }
}

static void destroy_pnj(pnj_t *pnj)
{
    pnj_t *tmp = pnj;
    pnj_t *stock = NULL;

    while (tmp != NULL){
        sfRectangleShape_destroy(tmp->hit_box);
        sfSprite_destroy(tmp->sprite);
        sfTexture_destroy(tmp->texture);
        sfRectangleShape_destroy(tmp->vision);
        destroy_text_box(tmp->text_box);
        stock = tmp;
        tmp = tmp->next;
        free(stock);
    }
}

void destroy_player(player_t *player)
{
    sfView_destroy(player->view);
    sfRectangleShape_destroy(player->hitbox);
    sfRectangleShape_destroy(player->atk_hitbox);
    sfTexture_destroy(player->texture);
    sfSprite_destroy(player->sprite);
    free(player->stat);
    free(player);
}

void destroy_video(video_t *video)
{
    sfTexture_destroy(video->back_p);
    sfTexture_destroy(video->front_p);
    sfSprite_destroy(video->back_player);
    sfSprite_destroy(video->front_player);
    sfClock_destroy(video->clock);
    sfRenderWindow_destroy(video->win);
}

void destroy_map1(entities_t *entities, all_menus_t *menus)
{
    destroy_pnj(entities->pnj);
    destroy_ennemies(entities->ennemies);
    destroy_all_menus(menus);
    free(menus);
}
