/*
** EPITECH PROJECT, 2025
** shoot
** File description:
** handle the weapon shooting
*/

#include "wolf.h"
#include <math.h>

static bool is_enemy_hit_3d(sfVector3f bull_start,
    sfVector3f bull_end, enemy_t *enemy)
{
    float dist_sq = 0.0;
    sfVector3f closest = {0, 0, 0};
    sfVector3f e_pos = {enemy->position.x, enemy->position.y,
        enemy->z + ENEMY_CENTER_Z};
    sfVector3f dir = {bull_end.x - bull_start.x, bull_end.y - bull_start.y,
        bull_end.z - bull_start.z};
    sfVector3f to_enemy = {e_pos.x - bull_start.x, e_pos.y - bull_start.y,
        e_pos.z - bull_start.z};
    float shoot =
        (to_enemy.x * dir.x + to_enemy.y * dir.y + to_enemy.z * dir.z) /
        (dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);

    shoot = fmaxf(0.0, fminf(1.0, shoot));
    closest.x = bull_start.x + dir.x * shoot;
    closest.y = bull_start.y + dir.y * shoot;
    closest.z = bull_start.z + dir.z * shoot;
    dist_sq = powf(closest.x - e_pos.x, 2) + powf(closest.y - e_pos.y, 2) +
        powf(closest.z - e_pos.z, 2);
    return dist_sq < BULLET_RADIUS * BULLET_RADIUS;
}

static void handle_state(sfVector3f start, sfVector3f end, enemy_t *enemy)
{
    if (is_enemy_hit_3d(start, end, enemy)) {
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
    float vertical_angle = MAX_PITCH * (MY_PI / 180.0f);
    float horizontal_angle = player->angle;
    sfVector3f dir3d = {cosf(horizontal_angle) * cosf(vertical_angle),
        sinf(horizontal_angle) * cosf(vertical_angle), sinf(vertical_angle)};
    sfVector3f start = {player->x, player->y, PLAYER_EYE_HEIGHT};
    sfVector3f end = {start.x + dir3d.x * BULLET_RANGE,
        start.y + dir3d.y * BULLET_RANGE, start.z + dir3d.z * BULLET_RANGE};

    for (size_t i = 0; i < manager->count; i++) {
        enemy = manager->enemies[i];
        if (!enemy || enemy->state == ENEMY_DEAD_ANIM_FINISHED)
            continue;
        handle_state(start, end, enemy);
    }
}
