/*
** EPITECH PROJECT, 2025
** main
** File description:
** the main
*/

#include "wolf.h"
#include "player.h"
#include <stdlib.h>
#include "weapons.h"
#include <string.h>
#include <stdio.h>
#include "handle_enemies.h"

static int handle_errors(int ac, const char **av)
{
    if (ac != 1) {
        fprintf(stderr, "Usage: %s (no arguments expected)\n", av[0]);
        return FAILURE;
    }
    if (getenv("DISPLAY") == NULL) {
        fprintf(stderr, "Error: DISPLAY environment variable is not set.\n");
        return FAILURE;
    }
    return SUCCESS;
}

static void handle_display(window_t *game)
{
    sfRenderWindow_setView(game->window, game->view);
    draw_sky(game, game->player);
    sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
    draw_floor(game->window, game->player->pitch);
}

static int display_window(window_t *game, enemy_manager_t *enemy_manager)
{
    float z_buffer[NUM_RAYS];

    while (sfRenderWindow_isOpen(game->window)) {
        game->elapsed = sfClock_restart(game->clock);
        game->delta_time = sfTime_asSeconds(game->elapsed);
        sfRenderWindow_clear(game->window, sfBlack);
        handle_display(game);
        handle_event(game, game->player, game->map_info, enemy_manager);
        cast_all_rays(game, game->player, game->map_info, z_buffer);
        handle_ennemies(game, enemy_manager, game->player, z_buffer);
        check_weapon(game->player, game);
        sfRenderWindow_display(game->window);
    }
    create_save(game->player);
    destroy_game(game, enemy_manager, game->player);
    return EXIT_SUCCESS;
}

int main(int ac, const char **av)
{
    window_t *game = NULL;
    enemy_manager_t *enemy_manager = NULL;

    if (handle_errors(ac, av) == FAILURE)
        return EXIT_FAILURE;
    game = init_window();
    game->map_info = init_map();
    game->player = init_player(game->map_info);
    enemy_manager = init_enemy_manager(game->map_info);
    if (game == NULL || game->player == NULL || enemy_manager == NULL)
        return EXIT_FAILURE;
    display_window(game, enemy_manager);
    return EXIT_SUCCESS;
}
