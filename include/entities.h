/*
** EPITECH PROJECT, 2024
** Myrpg
** File description:
** entities
*/

#ifndef ENTITIES_H_
    #define ENTITIES_H_
    #include "pnj.h"
    #include "ennemy.h"
    #include "chest.h"

typedef struct entities_s {
    pnj_t *pnj;
    ennemy_t *ennemies;
    chest_t *chest;
} entities_t;


void init_chest_sprite(chest_t *mob);
void init_pnj_sprite(pnj_t *mob);
void add_pnj(pnj_t **head, pnj_t *(func)(char *, char **), char *data,
    char **texte);
void add_ennemy(ennemy_t **head, ennemy_t *(func)(char *), char *data);
void add_chest(chest_t **head, chest_t *(func)(char *), char *data);
void init_ennemy_sprite_mage(ennemy_t *mob);
void init_ennemy_sprite_orc(ennemy_t *mob);
entities_t *init_entities(void);
#endif /* !ENTITIES_H_ */
