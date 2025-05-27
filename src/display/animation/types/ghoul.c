/*
** EPITECH PROJECT, 2025
** ghoul
** File description:
** animate the ghoul
*/

#include "init_enemies.h"

void handle_ghoul_pain(enemy_t *enemy, float delta_time)
{
    enemy->rect.left = GHOUL_HURTING;
    enemy->timer += delta_time;
    if (enemy->timer > GHOUL_HURT_TIME) {
        enemy->state = ENEMY_IDLE;
        enemy->timer = 0.0;
    }
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
}
