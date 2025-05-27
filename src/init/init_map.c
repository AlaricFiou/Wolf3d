/*
** EPITECH PROJECT, 2025
** init_map
** File description:
** init the map
*/

#include "wolf.h"
#include <stdlib.h>

static void free_map(int **map, size_t i)
{
    for (size_t j = 0; j < i; j++)
        free(map[j]);
    free(map);
}

static int **init_default_map(const int base_map[DEFAULT_MAP][DEFAULT_MAP])
{
    int **map = malloc(sizeof(int *) * DEFAULT_MAP);

    if (map == NULL)
        return NULL;
    for (size_t i = 0; i < DEFAULT_MAP; i++) {
        map[i] = malloc(sizeof(int) * DEFAULT_MAP);
        if (map[i] == NULL) {
            free_map(map, i);
            return NULL;
        }
        for (size_t j = 0; j < DEFAULT_MAP; j++)
            map[i][j] = base_map[i][j];
    }
    return map;
}

static int handle_default_map(map_info_t *map_info)
{
    static const int base_map[DEFAULT_MAP][DEFAULT_MAP] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 2, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1},
        {1, 3, 0, 0, 0, 0, 3, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };
    int **map = init_default_map(base_map);

    if (map == NULL)
        return FAILURE;
    map_info->rows = DEFAULT_MAP;
    map_info->cols = DEFAULT_MAP;
    map_info->map = map;
    return SUCCESS;
}

map_info_t *init_map(void)
{
    map_info_t *map_info = malloc(sizeof(map_info_t));

    if (map_info == NULL)
        return NULL;
    map_info->cols = 0;
    map_info->rows = 0;
    map_info->map = open_map("map.txt", map_info);
    if (map_info->map == NULL)
        handle_default_map(map_info);
    return map_info;
}
