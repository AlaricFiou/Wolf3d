/*
** EPITECH PROJECT, 2025
** display_enemies
** File description:
** handle the display of the enemies
*/

#include "wolf.h"
#include <math.h>
#include "handle_enemies.h"

static void update_enemy(enemy_t *enemy,
    player_t *player, float dt, map_info_t *map)
{
    if (enemy == NULL || enemy->state == ENEMY_DEAD)
        return;
    if (enemy->state != ENEMY_DEAD) {
        move_enemy_towards_player(enemy, player, dt, map);
        animate_enemy(enemy, dt);
    }
}

void update_all_enemies(enemy_manager_t *manager,
    player_t *player, float delta_time, map_info_t *map)
{
    enemy_t *enemy = NULL;

    for (size_t i = 0; i < manager->count; i++) {
        enemy = manager->enemies[i];
        if (enemy == NULL)
            continue;
        update_enemy(enemy, player, delta_time, map);
        if (is_player_hit_by_enemy(enemy, player))
            damage_on_player(player);
    }
}

static float get_enemy_distance(player_t *player, enemy_t *e)
{
    float dx = e->position.x - player->x;
    float dy = e->position.y - player->y;

    return dx * dx + dy * dy;
}

static bool compare_enemies(enemy_manager_t *manager, player_t *player,
    size_t a, size_t b)
{
    float da = get_enemy_distance(player, manager->enemies[a]);
    float db = get_enemy_distance(player, manager->enemies[b]);

    return da < db;
}

static size_t fill_valid_enemy_indices(enemy_manager_t *manager, size_t *order)
{
    size_t valid_count = 0;

    for (size_t i = 0; i < manager->count; i++) {
        if (manager->enemies[i] != NULL) {
            order[valid_count] = i;
            valid_count++;
        }
    }
    return valid_count;
}

static void sort_enemy_order(enemy_manager_t *manager,
    player_t *player, size_t *order)
{
    size_t j = 0;
    size_t tmp = 0;
    size_t valid_count = fill_valid_enemy_indices(manager, order);

    for (size_t i = 1; i < valid_count; i++) {
        j = i;
        while (j > 0 &&
            compare_enemies(manager, player, order[j - 1], order[j]) == true) {
            tmp = order[j];
            order[j] = order[j - 1];
            order[j - 1] = tmp;
            j--;
        }
    }
    for (size_t i = valid_count; i < manager->count; i++) {
        order[i] = (size_t)(-1);
    }
}

void draw_all_enemies(enemy_manager_t *manager,
    sfRenderWindow *window, player_t *player, float *z_buffer)
{
    size_t order[MAX_ENEMIES];
    enemy_t *enemy = NULL;

    sort_enemy_order(manager, player, order);
    for (size_t i = 0; i < manager->count; i++) {
        if (order[i] == (size_t)(-1))
            continue;
        enemy = manager->enemies[order[i]];
        if (enemy != NULL)
            draw_enemy_3d(window, player, enemy, z_buffer);
    }
}
