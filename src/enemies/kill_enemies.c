/*
** EPITECH PROJECT, 2025
** kill_enemies
** File description:
** free the memory when an anemy is killed
*/

#include "wolf.h"
#include "handle_enemies.h"

void cleanup_dead_enemies(enemy_manager_t *manager)
{
    enemy_t *enemy = NULL;

    for (size_t i = 0; i < manager->count; i++) {
        enemy = manager->enemies[i];
        if (enemy && enemy->state == ENEMY_DEAD_ANIM_FINISHED) {
            free_sprite(enemy->sprite, enemy->texture);
            free(enemy);
            manager->enemies[i] = NULL;
        }
    }
}
