/*
** EPITECH PROJECT, 2025
** handle_weapon
** File description:
** handle the display and status of the xeapon
*/

#include "wolf.h"

void update_weapon_position(window_t *game, weapon_t *weapon)
{
    sfVector2u win = sfRenderWindow_getSize(game->window);
    sfFloatRect rect = sfSprite_getGlobalBounds(weapon->sprite);
    float pos_x = (win.x - rect.width) / 2.0;
    float pos_y = win.y - rect.height - WEAPON_POS_HEIGHT;

    sfSprite_setPosition(weapon->sprite, (sfVector2f){pos_x, pos_y});
    sfSprite_setScale(weapon->sprite,
        (sfVector2f){SHOOTGUN_SIZE, SHOOTGUN_SIZE});
    sfSprite_setPosition(weapon->ex_sprite,
        (sfVector2f){win.x / 2 - 50, pos_y});
    sfSprite_setScale(weapon->ex_sprite, (sfVector2f){EX_SIZE, EX_SIZE});
}

void check_weapon(player_t *player, window_t *game)
{
    if (player == NULL || player->weapon == NULL)
        return;
    update_weapon_anim(player->weapon->shoot_anim,
        player->weapon->sprite, game->delta_time);
    update_explosion_anim(player->weapon->explosion_anim,
        player->weapon->ex_sprite, game->delta_time);
    update_weapon_position(game, player->weapon);
    if (player->weapon->explosion_anim->playing_ex)
        sfRenderWindow_drawSprite(game->window,
        player->weapon->ex_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, player->weapon->sprite, NULL);
}
