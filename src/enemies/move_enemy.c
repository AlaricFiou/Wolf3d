/*
** EPITECH PROJECT, 2025
** move_enemy
** File description:
** handle the enmy's movement
*/

#include <math.h>
#include "wolf.h"
#include "handle_enemies.h"

static void update_vector(sfVector2f *pos, enemy_t *enemy)
{
    sfVector2f pos_px = {
        enemy->position.x * TILE_SIZE,
        enemy->position.y * TILE_SIZE
    };

    (*pos).x = pos_px.x;
    (*pos).y = pos_px.y;
}

static sfVector2f calculate_enemy_movement(enemy_t *enemy,
    player_t *player, float dt)
{
    sfVector2f movement = {0, 0};
    float dx = player->x - enemy->position.x;
    float dy = player->y - enemy->position.y;
    float dist = sqrtf(dx * dx + dy * dy);

    if (dist < 0.1)
        return movement;
    enemy->angle = atan2f(dy, dx);
    movement.x = cosf(enemy->angle) * enemy->speed * dt;
    movement.y = sinf(enemy->angle) * enemy->speed * dt;
    return movement;
}

void move_enemy_towards_player(enemy_t *enemy,
    player_t *player, float dt, map_info_t *map)
{
    sfVector2f pos_px;
    sfVector2f move;
    float next_x;
    float next_y;

    if (enemy == NULL || enemy->state == ENEMY_DEAD)
        return;
    move = calculate_enemy_movement(enemy, player, dt);
    next_x = enemy->position.x + move.x;
    next_y = enemy->position.y + move.y;
    if (is_wall((int)next_x, (int)next_y, map)) {
        return;
    }
    enemy->position.x = next_x;
    enemy->position.y = next_y;
    update_vector(&pos_px, enemy);
    sfSprite_setPosition(enemy->sprite, pos_px);
}
