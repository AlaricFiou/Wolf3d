/*
** EPITECH PROJECT, 2025
** search
** File description:
** search values in the map
*/

#include "wolf.h"

static int is_target(int value, int id)
{
    if (value == id)
        return SUCCESS;
    return FAILURE;
}

static int try_fill_position(map_info_t *info,
    int row, sfVector2f *pos, int id)
{
    for (int col = 0; col < info->cols; col++) {
        if (is_target(info->map[row][col], id) == SUCCESS) {
            (*pos).x = col * TILE_SIZE + TILE_SIZE / 2;
            (*pos).y = row * TILE_SIZE + TILE_SIZE / 2;
            return SUCCESS;
        }
    }
    return FAILURE;
}

sfVector2f search_position(map_info_t *map_info, int id)
{
    sfVector2f pos = {-1, -1};

    for (int row = 0; row < map_info->rows; row++) {
        if (try_fill_position(map_info, row, &pos, id) == SUCCESS)
            break;
    }
    return pos;
}

int tile_type_case(sfVector2f case_pos, map_info_t *map)
{
    int col = (int)(case_pos.x);
    int row = (int)(case_pos.y);

    if (row < 0 || row >= map->rows || col < 0 || col >= map->cols)
        return OPEN_FAILURE;
    return map->map[row][col];
}
