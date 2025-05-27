/*
** EPITECH PROJECT, 2025
** destroy
** File description:
** free the memory
*/

#include "wolf.h"
#include <stdlib.h>
#include "handle_enemies.h"

void free_sprite(sfSprite *sprite, sfTexture *texture)
{
    if (sprite != NULL)
        sfSprite_destroy(sprite);
    if (texture != NULL)
        sfTexture_destroy(texture);
}

static void destroy_effects(effect_t *effect)
{
    if (effect->music != NULL)
        sfMusic_destroy(effect->music);
    if (effect->sound != NULL)
        sfSound_destroy(effect->sound);
    if (effect->sound_buffer != NULL)
        sfSoundBuffer_destroy(effect->sound_buffer);
}

static void destroy_manager(enemy_manager_t *enemy_manager)
{
    if (enemy_manager == NULL)
        return;
    for (size_t i = 0; i < enemy_manager->count; i++) {
        if (enemy_manager->enemies[i] != NULL) {
            free_sprite(enemy_manager->enemies[i]->sprite,
                enemy_manager->enemies[i]->texture);
            free(enemy_manager->enemies[i]);
        }
    }
    free(enemy_manager);
}

static void destroy_texture(window_t *game)
{
    sfSprite_destroy(game->sprite);
    sfTexture_destroy(game->texture);
    sfRenderWindow_destroy(game->window);
}

static void destroy_anim(anim_t *anim)
{
    if (anim == NULL)
        return;
    if (anim->frames != NULL)
        free(anim->frames);
    free(anim);
}

static void destroy_weapon_list(weapon_t *weapon)
{
    weapon_t *tmp = NULL;

    while (weapon != NULL) {
        tmp = weapon->next;
        free_sprite(weapon->sprite, weapon->texture);
        weapon->sprite = NULL;
        weapon->texture = NULL;
        free_sprite(weapon->ex_sprite, weapon->ex_texture);
        weapon->ex_sprite = NULL;
        weapon->ex_texture = NULL;
        destroy_anim(weapon->shoot_anim);
        weapon->shoot_anim = NULL;
        destroy_anim(weapon->explosion_anim);
        weapon->explosion_anim = NULL;
        free(weapon);
        weapon = tmp;
    }
}

static void destroy_player(player_t *player)
{
    destroy_weapon_list(player->weapon);
    free(player);
}

void destroy_game(window_t *game,
    enemy_manager_t *enemy_manager, player_t *player)
{
    destroy_texture(game);
    destroy_effects(&game->effect);
    destroy_manager(enemy_manager);
    destroy_player(player);
    sfClock_destroy(game->clock);
    if (game->map_info != NULL) {
        for (int i = 0; i < game->map_info->rows; i++)
            free(game->map_info->map[i]);
        free(game->map_info->map);
        free(game->map_info);
    }
    free(game);
}
