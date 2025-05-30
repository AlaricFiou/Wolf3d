/*
** EPITECH PROJECT, 2025
** init_enemies
** File description:
** init the enemies
*/

#ifndef INIT_ENEMIES_H_
    #define INIT_ENEMIES_H_
    #include "handle_enemies.h"

//POINTEURS TAB

typedef void (*pain_handler_t)(enemy_t *, float);
typedef enemy_t *(*enemy_init_func_t)(sfVector2f);

//STRUCT

typedef struct enemy_desc_s {
    const char *name;
    int id;
    enemy_init_func_t init;
} enemy_desc_t;

//FUNCTIONS

enemy_t *init_ghoul_enemy(sfVector2f pos);

//TAB

static const enemy_desc_t enemy_descs[] = {
    {"Ghoul", GHOUL_ID, init_ghoul_enemy},
    {NULL, 0, NULL}
};

#endif /* !INIT_ENEMIES_H_ */
