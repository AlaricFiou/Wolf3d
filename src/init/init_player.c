/*
** EPITECH PROJECT, 2025
** init_player
** File description:
** init the player and its position
*/

#include "wolf.h"
#include "player.h"
#include <stdlib.h>
#include "weapons.h"

player_t *init_player(map_info_t *map_info)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f pos = {0, 0};

    if (player == NULL)
        return NULL;
    if (open_save(player) == FAILURE) {
        pos = search_position(map_info, PLAYER_ID);
        player->x = pos.x;
        player->y = pos.y;
        player->hp = PLAYER_HP;
        player->score = 0;
    }
    player->angle = 0.0;
    player->pitch = 0.0;
    player->weapon = init_weapon_list();
    player->invincibility_timer = PLAYER_INVINCIBILITY;
    return player;
}
