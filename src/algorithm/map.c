/*
** EPITECH PROJECT, 2025
** map_utils
** File description:
** check walls
*/

#include "wolf.h"

int is_wall(int x, int y, map_info_t *map_info)
{
    int tx = x / TILE_SIZE;
    int ty = y / TILE_SIZE;

    if (tx < 0 || tx >= map_info->rows || ty < 0 || ty >= map_info->cols)
        return 1;
    return map_info->map[ty][tx] == 1;
}
