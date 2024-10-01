/*
** EPITECH PROJECT, 2024
** init player part2
** File description:
** init_player_part2
*/

#include "player.h"
#include "path_assets.h"
#include "rpg.h"

hud_t *init_hud_player(void)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->texture = sfTexture_createFromFile(path_assets[HUD], NULL);
    hud->sprite = sfSprite_create();
    sfSprite_setTexture(hud->sprite, hud->texture, sfTrue);
    sfSprite_setScale(hud->sprite, (sfVector2f){0.25, 0.25});
    hud->font = sfFont_createFromFile(path_assets[FONT]);
    hud->level = sfText_create();
    sfText_setFont(hud->level, hud->font);
    sfText_setScale(hud->level, (sfVector2f){0.4, 0.4});
    sfText_setColor(hud->level, sfBlack);
    hud->pos = (sfVector2f){0.0, 0.0};
    hud->health = create_rectangle((sfVector2f){0.0, 0.0},
    (sfVector2f){50, 3}, 0, sfRed);
    sfRectangleShape_setFillColor(hud->health, sfRed);
    hud->xp = create_rectangle((sfVector2f){0.0, 0.0},
    (sfVector2f){35, 2}, 0, sfBlue);
    sfRectangleShape_setFillColor(hud->xp, sfBlue);
    sfText_setString(hud->level, "1");
    return hud;
}

static xp_t *init_xp(void)
{
    xp_t *xp = malloc(sizeof(xp_t));

    xp->xp = get_stat_value("xp");
    xp->level = get_stat_value("level");
    xp->credit = get_stat_value("credit");
    xp->target_xp = TARGET_XP_BASE + (DELTA_XP_TARGET * (xp->level - 1));
    return xp;
}

static stat_t *init_stat_player(void)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->attack = get_stat_value("attack");
    stat->defense = get_stat_value("defense");
    stat->health = get_stat_value("health");
    stat->max_health = get_stat_value("max_health");
    stat->speed = get_stat_value("speed");
    return stat;
}

void init_delta_t(player_t *player)
{
    player->t_anim = 0;
    player->t_move = 0;
}

void init_stat_and_xp_default(player_t *player)
{
    player->stat = init_default_player_stat();
    player->xp = init_default_player_xp();
}

void init_stat_and_xp(player_t *player)
{
    player->stat = init_stat_player();
    player->xp = init_xp();
}
