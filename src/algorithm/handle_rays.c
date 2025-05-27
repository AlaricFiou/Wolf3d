/*
** EPITECH PROJECT, 2025
** handle_ray
** File description:
** handle the calculs and position of the rays
*/

#include <math.h>
#include "wolf.h"

void cast_all_rays(window_t *game,
    player_t *player, map_info_t *map_info, float *z_buffer)
{
    float angle = 0;
    float height = 0;
    float angle_dist = 0;
    float step = FOV / NUM_RAYS;
    float start = player->angle - (FOV / 2);
    int count_rays = 0;

    for (size_t col = 0; col < NUM_RAYS; col++) {
        angle = start + (col * step);
        map_info->dist = is_wall_hit(player, angle, map_info);
        angle_dist = map_info->dist * cos(angle - player->angle);
        z_buffer[col] = angle_dist;
        height = (TILE_SIZE / angle_dist) * (SIZE_X / 2);
        count_rays += 1;
        render_wall(game, col, height, count_rays);
    }
}
