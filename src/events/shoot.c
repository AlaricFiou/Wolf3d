/*
** EPITECH PROJECT, 2025
** shoot
** File description:
** handle the weapon shooting
*/

#include "wolf.h"
#include <math.h>

static bool is_enemy_hit(sfVector2f bullet_start,
    sfVector2f bullet_end, enemy_t *enemy)
{
    sfVector2f closest_point;
    float distance_squared = 0.0;
    sfVector2f e_pos = enemy->position;
    sfVector2f shot_direction = {bullet_end.x - bullet_start.x,
        bullet_end.y - bullet_start.y};
    sfVector2f e_vector = {e_pos.x - bullet_start.x, e_pos.y - bullet_start.y};
    float get_position = e_vector.x * shot_direction.x +
        e_vector.y * shot_direction.y;
    float direction_lenght =
        shot_direction.x * shot_direction.x +
        shot_direction.y * shot_direction.y;
    float hit_e = get_position / direction_lenght;

    hit_e = fmaxf(0.0, fminf(1.0, hit_e));
    closest_point.x = bullet_start.x + hit_e * shot_direction.x;
    closest_point.y = bullet_start.y + hit_e * shot_direction.y;
    distance_squared = powf(closest_point.x - e_pos.x, 2) +
        powf(closest_point.y - e_pos.y, 2);
    return distance_squared < BULLET_RADIUS * BULLET_RADIUS;
}

static void handle_state(sfVector2f start, sfVector2f end, enemy_t *enemy)
{
    if (is_enemy_hit(start, end, enemy)) {
        enemy->hp -= BULLET_DAMAGE;
        if (enemy->hp <= 0) {
            enemy->state = ENEMY_DEAD;
        } else {
            enemy->state = ENEMY_PAIN;
            enemy->timer = 0.0;
        }
    }
}

void shoot_bullet(player_t *player, enemy_manager_t *manager)
{
    enemy_t *enemy = NULL;
    float angle = player->angle;
    sfVector2f start = {player->x, player->y};
    sfVector2f dir = {
        cosf(angle) * BULLET_RANGE,
        sinf(angle) * BULLET_RANGE
    };
    sfVector2f end = {
        start.x + dir.x,
        start.y + dir.y
    };

    for (size_t i = 0; i < manager->count; i++) {
        enemy = manager->enemies[i];
        if (enemy == NULL)
            continue;
        if (enemy->state == ENEMY_DEAD_ANIM_FINISHED)
            continue;
        handle_state(start, end, enemy);
    }
}
