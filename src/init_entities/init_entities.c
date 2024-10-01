/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** init_mobs
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

static char *didactitiel[] = {
    "Press 'z' 'q' 's' 'd' to move...",
    "Press 'e' to open the inventory and 'Escape' for the settings...",
    "Press 'j' or right-click to attack...",
    "I think there's a problem in the south of the village !",
    NULL,
};

static char *gourdin[] = {
    "Hello to you, adventurer!! A chestplate is hidden in the forest.",
    "Be careful, the forest can be dangerous...",
    "Take the gourdin from the chest and equip it!!",
    NULL,
};

static char *ouest[] = {
    "It seems that in the west, ",
    "one of the three fragments is firmly guarded ",
    "they're a bunch of fripouilles !! ",
    "Take care of yourself ",
    NULL,
};

static char *maison[] = {
    "A group of crapule stormed my house ",
    "Please help me... ",
    NULL,
};

static char *lore[] = {
    "It'S HORRIBLE !!!",
    "Recently, all the color of the world dispeared. ",
    "I think you can bring the color back ",
    "You have to assemble the color fragments. ",
    "They are spread out in the world. ",
    "You are the only one who can do it. ",
    NULL
};


static pnj_t *init_pnj(char *infos, char **texte)
{
    pnj_t *mob = malloc(sizeof(ennemy_t));
    char **data = my_str_to_word_array(infos, ";");

    mob->pos.x = my_getnbr(data[0]);
    mob->pos.y = my_getnbr(data[1]);
    mob->hit_box = create_rectangle((sfVector2f)
    {mob->pos.x + 8, mob->pos.y + 8}, (sfVector2f){16, 16}, 0, sfRed);
    mob->vision = create_rectangle((sfVector2f)
    {mob->pos.x - 2, mob->pos.y - 2}, (sfVector2f){35, 35}, 0, sfBlack);
    mob->text_box = init_text(texte, (sfVector2f){100, 1000});
    init_pnj_sprite(mob);
    mob->t_anim = 0.0;
    mob->next = NULL;
    return mob;
}

static ennemy_t *init_ennemy(char *infos)
{
    ennemy_t *mob = malloc(sizeof(ennemy_t));

    assign_infos_ennemy(mob, infos);
    mob->looking_at = 0;
    mob->hit_box = create_rectangle((sfVector2f)
    {mob->pos.x + 8, mob->pos.y + 8}, (sfVector2f){16, 16}, 0, sfRed);
    mob->vision = create_rectangle((sfVector2f)
    {mob->pos.x - 44, mob->pos.y - 45}, (sfVector2f){120, 120}, 0, sfGreen);
    init_delta_t_ennemy(mob);
    mob->hurt = 0;
    mob->kb_vector = (sfVector2i){0, 0};
    init_ennemy_sprite(mob);
    mob->next = NULL;
    return mob;
}

static ennemy_t *init_ennemy_mage(char *infos)
{
    ennemy_t *mob = malloc(sizeof(ennemy_t));

    assign_infos_ennemy(mob, infos);
    mob->looking_at = 0;
    mob->hit_box = create_rectangle((sfVector2f)
    {mob->pos.x + 8, mob->pos.y + 8}, (sfVector2f){16, 16}, 0, sfRed);
    mob->vision = create_rectangle((sfVector2f)
    {mob->pos.x - 44, mob->pos.y - 45}, (sfVector2f){120, 120}, 0, sfGreen);
    init_delta_t_ennemy(mob);
    mob->hurt = 0;
    mob->kb_vector = (sfVector2i){0, 0};
    init_ennemy_sprite_mage(mob);
    mob->next = NULL;
    return mob;
}

static ennemy_t *init_ennemy_orc(char *infos)
{
    ennemy_t *mob = malloc(sizeof(ennemy_t));

    assign_infos_ennemy(mob, infos);
    mob->looking_at = 0;
    mob->hit_box = create_rectangle((sfVector2f)
    {mob->pos.x + 8, mob->pos.y + 8}, (sfVector2f){16, 16}, 0, sfRed);
    mob->vision = create_rectangle((sfVector2f)
    {mob->pos.x - 44, mob->pos.y - 45}, (sfVector2f){120, 120}, 0, sfGreen);
    init_delta_t_ennemy(mob);
    mob->hurt = 0;
    mob->kb_vector = (sfVector2i){0, 0};
    init_ennemy_sprite_orc(mob);
    mob->next = NULL;
    return mob;
}

static chest_t *init_chest(char *infos)
{
    chest_t *mob = malloc(sizeof(ennemy_t));
    char **data = my_str_to_word_array(infos, ";");

    mob->chest = sfMusic_createFromFile("./assets/music/chest.ogg");
    mob->pos.x = my_getnbr(data[0]);
    mob->pos.y = my_getnbr(data[1]);
    mob->obj_name = my_strdup(data[2]);
    mob->hit_box = create_rectangle((sfVector2f)
    {mob->pos.x, mob->pos.y}, (sfVector2f){16, 16}, 0, sfRed);
    mob->opened = 0;
    mob->opening = 0;
    mob->t_anim = 0.0;
    init_chest_sprite(mob);
    mob->next = NULL;
    return mob;
}

static void create_all_ennemies(entities_t *ent)
{
    char **arr = load_array_from_file("src/config/ennemies.txt");
    char **tmp = NULL;

    for (int i = 0; arr[i]; i++) {
        tmp = my_str_to_word_array(arr[i], " ");
        if (strcmp(tmp[0], "simple") == 0)
            add_ennemy(&ent->ennemies, &init_ennemy, tmp[1]);
        if (strcmp(tmp[0], "mage") == 0)
            add_ennemy(&ent->ennemies, &init_ennemy_mage, tmp[1]);
        if (strcmp(tmp[0], "orc") == 0)
            add_ennemy(&ent->ennemies, &init_ennemy_orc, tmp[1]);
    }
}

static void create_all_pnj(entities_t *ent)
{
    char **arr = load_array_from_file("src/config/pnj.txt");
    char **tmp = NULL;

    for (int i = 0; arr[i]; i++) {
        tmp = my_str_to_word_array(arr[i], " ");
        if (strcmp(tmp[1], "didactitiel") == 0)
            add_pnj(&ent->pnj, &init_pnj, tmp[0], didactitiel);
        if (strcmp(tmp[1], "lore") == 0)
            add_pnj(&ent->pnj, &init_pnj, tmp[0], lore);
        if (strcmp(tmp[1], "gourdin") == 0)
            add_pnj(&ent->pnj, &init_pnj, tmp[0], gourdin);
        if (strcmp(tmp[1], "ouest") == 0)
            add_pnj(&ent->pnj, &init_pnj, tmp[0], ouest);
        if (strcmp(tmp[1], "maison") == 0)
            add_pnj(&ent->pnj, &init_pnj, tmp[0], maison);
    }
}

static void create_all_chests(entities_t *ent)
{
    char **arr = load_array_from_file("src/config/chest.txt");

    for (int i = 0; arr[i]; i++) {
        add_chest(&ent->chest, &init_chest, arr[i]);
    }
}

entities_t *init_entities(void)
{
    entities_t *ent = malloc(sizeof(entities_t));

    ent->ennemies = NULL;
    ent->pnj = NULL;
    ent->chest = NULL;
    create_all_pnj(ent);
    create_all_chests(ent);
    create_all_ennemies(ent);
    return ent;
}
