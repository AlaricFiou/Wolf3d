/*
** EPITECH PROJECT, 2025
** animate_enemy
** File description:
** animate the anemy given
*/

#include <math.h>
#include "handle_enemies.h"

void handle_status(enemy_t *enemy, float delta_time)
{
    if (enemy->state == ENEMY_PAIN) {
        enemy->rect.left = GHOUL_HURTING;
        enemy->timer += delta_time;
        if (enemy->timer > 0.2) {
            enemy->state = ENEMY_IDLE;
            enemy->timer = 0.0;
        }
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
        return;
    }
}

void animate_enemy(enemy_t *enemy, float delta_time)
{
    int end = 0;

    if (enemy == NULL || enemy->sprite == NULL)
        return;
    handle_status(enemy, delta_time);
    if (enemy->state == ENEMY_PAIN)
        return;
    enemy->timer += delta_time;
    if (enemy->timer < ANIMATION_SPEED)
        return;
    enemy->timer = 0.0;
    enemy->rect.left += enemy->rect.width + 2;
    end = enemy->start_left + (enemy->frames * (enemy->rect.width + 2));
    if (enemy->rect.left >= end)
        enemy->rect.left = enemy->start_left;
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
}
