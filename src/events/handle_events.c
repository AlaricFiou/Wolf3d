/*
** EPITECH PROJECT, 2025
** handle_event
** File description:
** handle the differents events
*/

#include "wolf.h"
#include "player.h"

static void handle_music(sfEvent event, sfMusic *music)
{
    if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyP && music != NULL) {
        if (sfMusic_getStatus(music) == sfPlaying)
            sfMusic_pause(music);
        else
            sfMusic_play(music);
    }
}

static void handle_enemy(window_t *game, enemy_manager_t *enemy_manager,
    player_t *player)
{
    enemy_t *enemy = NULL;

    for (size_t i = 0; i < enemy_manager->count; i++) {
        enemy = enemy_manager->enemies[i];
        if (enemy == NULL)
            continue;
        if (enemy->state == ENEMY_DEAD) {
            animate_ghoul_death(enemy, game->delta_time);
        }
        if (enemy->state == ENEMY_DEAD_ANIM_FINISHED) {
            free_sprite(enemy->sprite, enemy->texture);
            free(enemy);
            enemy_manager->enemies[i] = NULL;
            player->score += GHOUL_SCORE;
            printf("YOUR SCORE: %ld\n", player->score);
        }
    }
}

static void handle_input(sfEvent event, window_t *game,
    player_t *player, enemy_manager_t *enemy_manager)
{
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        player->weapon->shoot_anim->playing == false) {
        shoot_bullet(player, enemy_manager);
        start_animation(player->weapon->shoot_anim, player->weapon->sprite);
        start_animation(player->weapon->explosion_anim,
            player->weapon->ex_sprite);
        sfSound_play(game->effect.sound);
    }
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyF))
        game->effect.flashlight = !game->effect.flashlight;
}

static void handle_resize(window_t *game)
{
    sfVector2u new_size = {0, 0};

    if (game->event.type == sfEvtResized) {
        new_size.x = game->event.size.width;
        new_size.y = game->event.size.height;
        sfView_setSize(game->view, (sfVector2f){new_size.x, new_size.y});
        sfView_setCenter(game->view,
            (sfVector2f){new_size.x / 2.0, new_size.y / 2.0});
        sfRenderWindow_setView(game->window, game->view);
    }
}

void handle_event(window_t *game, player_t *player,
    map_info_t *map_info, enemy_manager_t *enemy_manager)
{
    handle_player(player, map_info, game->delta_time);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if ((game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyEscape) ||
            game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        handle_input(game->event, game, player, enemy_manager);
        handle_music(game->event, game->effect.music);
        handle_resize(game);
    }
    handle_enemy(game, enemy_manager, player);
}
