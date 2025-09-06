#include <math.h>
#include "player.h"
#include "wolf.h"

static void update_player_position(player_t *player, map_info_t *map_info, float x, float y)
{
    int map_x = (int)(x / TILE_SIZE);
    int map_y = (int)(y / TILE_SIZE);

    if (map_x < 0 || map_y < 0 || map_y >= map_info->rows || map_x >= map_info->cols)
        return;

    if (map_info->map[map_y][map_x] != IS_WALL) {
        player->x = x;
        player->y = y;
    }
}

void move_forward(player_t *player, map_info_t *map_info)
{
    float x = player->x + cos(player->angle) * MOVE_SPEED;
    float y = player->y + sin(player->angle) * MOVE_SPEED;
    update_player_position(player, map_info, x, y);
}

void move_backward(player_t *player, map_info_t *map_info)
{
    float x = player->x - cos(player->angle) * MOVE_SPEED;
    float y = player->y - sin(player->angle) * MOVE_SPEED;
    update_player_position(player, map_info, x, y);
}

void move_left(player_t *player, map_info_t *map_info)
{
    float x = player->x + cos(player->angle - MY_PI / 2) * MOVE_SPEED;
    float y = player->y + sin(player->angle - MY_PI / 2) * MOVE_SPEED;
    update_player_position(player, map_info, x, y);
}

void move_right(player_t *player, map_info_t *map_info)
{
    float x = player->x + cos(player->angle + MY_PI / 2) * MOVE_SPEED;
    float y = player->y + sin(player->angle + MY_PI / 2) * MOVE_SPEED;
    update_player_position(player, map_info, x, y);
}

void special_case(player_t *player)
{
    if (player->angle < 0)
        player->angle += 2 * MY_PI;
    else if (player->angle >= 2 * MY_PI)
        player->angle -= 2 * MY_PI;
}
