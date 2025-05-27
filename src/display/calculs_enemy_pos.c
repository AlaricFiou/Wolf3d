/*
** EPITECH PROJECT, 2025
** calculs_enemy_pos
** File description:
** handle the z angle
*/

#include "wolf.h"
#include <math.h>

static void project_enemy(player_t *player, enemy_t *enemy,
    float *sx, float *dist)
{
    float dx = enemy->position.x - player->x;
    float dy = enemy->position.y - player->y;
    float angle = atan2f(dy, dx) - player->angle;

    angle = fmodf(angle + 3 * MY_PI, 2 * MY_PI) - MY_PI;
    *dist = sqrtf(dx * dx + dy * dy);
    *sx = (angle + (FOV / 2)) * SIZE_X / FOV;
}

static void set_enemy_sprite(enemy_t *enemy, int x, int h, player_t *player)
{
    float scale = (float)h / enemy->rect.height;
    sfVector2f pos = {
        x - (enemy->rect.width * scale) / 2,
        (SIZE_Y - h) / 2 + player->pitch
    };
    sfVector2f sc = {scale, scale};

    sfSprite_setScale(enemy->sprite, sc);
    sfSprite_setPosition(enemy->sprite, pos);
}

void draw_enemy_3d(sfRenderWindow *window, player_t *player,
    enemy_t *enemy, float *z)
{
    float sx = 0;
    float dist = 0;
    int col = 0;
    float height = 0;

    project_enemy(player, enemy, &sx, &dist);
    if (dist < 0.5 || sx < 0 || sx >= SIZE_X || dist >= z[(int)sx])
        return;
    height = (int)(TILE_SIZE / dist * (SIZE_X / 2));
    col = (int)sx;
    set_enemy_sprite(enemy, col, height, player);
    sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
}
