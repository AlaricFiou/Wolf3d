/*
** EPITECH PROJECT, 2025
** player
** File description:
** handle the player
*/

#include <math.h>
#include "player.h"
#include <SFML/Window/Keyboard.h>

int damage_on_player(player_t *player)
{
    if (player->invincibility_timer <= 0.0) {
        player->hp -= ENEMY_DAMAGE;
        if (player->hp == PLAYER_DEAD)
            return PLAYER_DEAD;
        player->invincibility_timer = PLAYER_INVINCIBILITY;
    }
    return player->hp;
}

bool is_player_hit_by_enemy(enemy_t *enemy, player_t *player)
{
    float dx = 0.0;
    float dy = 0.0;
    float distance_sq = 0.0;

    if (enemy == NULL)
        return false;
    dx = enemy->position.x - player->x;
    dy = enemy->position.y - player->y;
    distance_sq = dx * dx + dy * dy;
    return distance_sq < ENEMY_ATTACK_RADIUS * ENEMY_ATTACK_RADIUS;
}

void handle_player(player_t *player, map_info_t *map_info, float delta_time)
{
    const size_t len = sizeof(controls) / sizeof(control_t);

    for (size_t i = 0; i < len; i++) {
        if (sfKeyboard_isKeyPressed(controls[i].key))
            controls[i].action(player, map_info);
    }
    if (player->invincibility_timer > 0.0)
        player->invincibility_timer -= delta_time;
    special_case(player);
}
