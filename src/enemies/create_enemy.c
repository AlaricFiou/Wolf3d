/*
** EPITECH PROJECT, 2025
** create_enemy
** File description:
** create the enemy struct and set his parameter
*/

#include "wolf.h"
#include <string.h>
#include <stdlib.h>
#include "player.h"
#include "init_enemies.h"

enemy_t *add_enemy_by_id(int id, sfVector2f pos)
{
    for (size_t i = 0; enemy_descs[i].name != NULL; i++) {
        if (enemy_descs[i].id == id) {
            return enemy_descs[i].init(pos);
        }
    }
    return NULL;
}

static void try_add_enemy(enemy_manager_t *manager, int tile_id, int x, int y)
{
    sfVector2f pos = {-1, -1};
    enemy_t *enemy = NULL;

    if (tile_id != PLAYER_ID && tile_id > 1) {
        if (manager->count >= MAX_ENEMIES)
            return;
        pos.x = x * TILE_SIZE + TILE_SIZE / 2;
        pos.y = y * TILE_SIZE + TILE_SIZE / 2;
        enemy = add_enemy_by_id(tile_id, pos);
        if (enemy != NULL) {
            manager->enemies[manager->count] = enemy;
            manager->count++;
        }
    }
}

enemy_manager_t *init_enemy_manager(map_info_t *map_info)
{
    int x = 0;
    int y = 0;
    int tile_id = 0;
    enemy_manager_t *manager = NULL;

    manager = malloc(sizeof(enemy_manager_t));
    if (manager == NULL)
        return NULL;
    manager->count = 0;
    for (y = 0; y < map_info->rows; y++) {
        for (x = 0; x < map_info->cols; x++) {
            tile_id = map_info->map[y][x];
            try_add_enemy(manager, tile_id, x, y);
        }
    }
    return manager;
}
