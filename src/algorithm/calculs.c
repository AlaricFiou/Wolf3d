/*
** EPITECH PROJECT, 2025
** calculs
** File description:
** the calculs for the ray
*/

#include <math.h>
#include "wolf.h"

static float normalize_angle(float angle)
{
    angle = fmod(angle, 2 * MY_PI);
    if (angle < 0)
        angle += 2 * MY_PI;
    return angle;
}

static void set_ray_dir(ray_t *rayon, float angle)
{
    rayon->ray_dir_x = cos(angle);
    rayon->ray_dir_y = sin(angle);
}

static void set_deltas(ray_t *rayon)
{
    rayon->delta_x = fabs(1.0 / rayon->ray_dir_x);
    rayon->delta_y = fabs(1.0 / rayon->ray_dir_y);
}

static void set_steps(player_t *p, map_info_t *m)
{
    int mx = p->x / TILE_SIZE;
    int my = p->y / TILE_SIZE;

    if (m->ray.ray_dir_x < 0) {
        m->ray.step_x = LONGER_PATH;
        m->ray.side_x = (p->x - mx * TILE_SIZE) * m->ray.delta_x / TILE_SIZE;
    } else {
        m->ray.step_x = SHORTER_PATH;
        m->ray.side_x =
            ((mx + 1) * TILE_SIZE - p->x) * m->ray.delta_x / TILE_SIZE;
    }
    if (m->ray.ray_dir_y < 0) {
        m->ray.step_y = LONGER_PATH;
        m->ray.side_y = (p->y - my * TILE_SIZE) * m->ray.delta_y / TILE_SIZE;
    } else {
        m->ray.step_y = SHORTER_PATH;
        m->ray.side_y =
            ((my + 1) * TILE_SIZE - p->y) * m->ray.delta_y / TILE_SIZE;
    }
}

static float dda_algorithm(player_t *p, map_info_t *m)
{
    int mx = p->x / TILE_SIZE;
    int my = p->y / TILE_SIZE;

    while (1) {
        if (m->ray.side_x < m->ray.side_y) {
            m->ray.side_x += m->ray.delta_x;
            mx += m->ray.step_x;
            m->ray.side = IS_EMPTY;
        } else {
            m->ray.side_y += m->ray.delta_y;
            my += m->ray.step_y;
            m->ray.side = IS_WALL;
        }
        if (mx < 0 || my < 0 || mx >= m->cols || my >= m->rows)
            return NO_WALL_FOUND;
        if (m->map[my][mx] == IS_WALL)
            return (m->ray.side == IS_EMPTY)
                ? (m->ray.side_x - m->ray.delta_x) * TILE_SIZE
                : (m->ray.side_y - m->ray.delta_y) * TILE_SIZE;
    }
}

float is_wall_hit(player_t *player, float angle, map_info_t *map_info)
{
    angle = normalize_angle(angle);
    set_ray_dir(&map_info->ray, angle);
    set_deltas(&map_info->ray);
    set_steps(player, map_info);
    return dda_algorithm(player, map_info);
}
