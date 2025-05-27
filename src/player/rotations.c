/*
** EPITECH PROJECT, 2025
** rotation
** File description:
** handle the player rotations
*/

#include <math.h>
#include "player.h"

void rotate_left(player_t *player, map_info_t *map_info)
{
    (void)map_info;
    player->angle -= ROT_SPEED;
}

void rotate_right(player_t *player, map_info_t *map_info)
{
    (void)map_info;
    player->angle += ROT_SPEED;
}

void look_up(player_t *player, map_info_t *map_info)
{
    (void)map_info;
    player->pitch += PITCH_SPEED;
    if (player->pitch > MAX_PITCH)
        player->pitch = MAX_PITCH;
}

void look_down(player_t *player, map_info_t *map_info)
{
    (void)map_info;
    player->pitch -= PITCH_SPEED;
    if (player->pitch < MIN_PITCH)
        player->pitch = MIN_PITCH;
}
