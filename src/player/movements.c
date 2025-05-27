/*
** EPITECH PROJECT, 2025
** movement
** File description:
** handle the player movements
*/

#include <math.h>
#include "player.h"

void move_forward(player_t *player, map_info_t *map_info)
{
    float x = player->x + cos(player->angle) * MOVE_SPEED;
    float y = player->y + sin(player->angle) * MOVE_SPEED;

    if (!is_wall(x, y, map_info)) {
        player->x = x;
        player->y = y;
    }
}

void move_backward(player_t *player, map_info_t *map_info)
{
    float x = player->x - cos(player->angle) * MOVE_SPEED;
    float y = player->y - sin(player->angle) * MOVE_SPEED;

    if (!is_wall(x, y, map_info)) {
        player->x = x;
        player->y = y;
    }
}

void move_left(player_t *player, map_info_t *map_info)
{
    float x = player->x + cos(player->angle - MY_PI / 2) * MOVE_SPEED;
    float y = player->y + sin(player->angle - MY_PI / 2) * MOVE_SPEED;

    if (!is_wall(x, y, map_info)) {
        player->x = x;
        player->y = y;
    }
}

void move_right(player_t *player, map_info_t *map_info)
{
    float x = player->x + cos(player->angle + MY_PI / 2) * MOVE_SPEED;
    float y = player->y + sin(player->angle + MY_PI / 2) * MOVE_SPEED;

    if (!is_wall(x, y, map_info)) {
        player->x = x;
        player->y = y;
    }
}

void special_case(player_t *player)
{
    if (player->angle < 0)
        player->angle += 2 * MY_PI;
    else if (player->angle > 2 * MY_PI)
        player->angle -= 2 * MY_PI;
}
