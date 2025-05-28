/*
** EPITECH PROJECT, 2025
** set_rect
** File description:
** handle the rect for the animation
*/

#include <stdlib.h>
#include "wolf.h"
#include "handle_enemies.h"

static void set_values(sfVector2f pos, enemy_t *enemy)
{
    enemy->z = 0.0;
    enemy->timer = 0.0;
    enemy->angle = 0.0;
    enemy->death_frame = 0;
    enemy->position = pos;
    enemy->hp = GHOUL_HP;
    enemy->speed = GHOUL_SPEED;
    enemy->id = GHOUL_ID;
    enemy->state = ENEMY_IDLE;
    enemy->start_left = GHOUL_LEFT_IDLE;
    enemy->frames = GHOUL_FRAMES;
    enemy->rect = (sfIntRect){GHOUL_LEFT_IDLE,
        GHOUL_TOP, GHOUL_WIDTH, GHOUL_HEIGHT};
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfSprite_setScale(enemy->sprite, (sfVector2f){9, 9});
    sfSprite_setPosition(enemy->sprite, pos);
}

enemy_t *init_ghoul_enemy(sfVector2f pos)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    if (enemy == NULL)
        return NULL;
    enemy->texture = sfTexture_createFromFile(GHOUL_PATH, NULL);
    if (enemy->texture == NULL) {
        free(enemy);
        return NULL;
    }
    enemy->sprite = sfSprite_create();
    if (enemy->sprite == NULL) {
        sfTexture_destroy(enemy->texture);
        free(enemy);
        return NULL;
    }
    set_values(pos, enemy);
    return enemy;
}
