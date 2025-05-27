/*
** EPITECH PROJECT, 2025
** handle_ennemies
** File description:
** handle the enemies status
*/

#include "wolf.h"

void handle_ennemies(window_t *game, enemy_manager_t *enemy_manager,
    player_t *player, float *z_buffer)
{
    update_all_enemies(enemy_manager, player,
        game->delta_time, game->map_info);
    draw_all_enemies(enemy_manager, game->window, player, z_buffer);
    cleanup_dead_enemies(enemy_manager);
}
