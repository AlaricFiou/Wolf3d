/*
** EPITECH PROJECT, 2025
** background
** File description:
** display the background
*/

#include "wolf.h"

static void display_sky(window_t *game,
    float pitch, sfIntRect rect1, sfIntRect rect2)
{
    if (rect1.width < SIZE_X) {
        sfSprite_setTextureRect(game->sprite, rect2);
        sfSprite_setPosition(game->sprite, (sfVector2f){rect1.width, pitch});
        sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
    }
}

void draw_sky(window_t *game, player_t *player)
{
    int width = sfTexture_getSize(game->texture).x;
    int height = sfTexture_getSize(game->texture).y;
    int offset_x = (int)(player->angle * ((float)width / (2 * MY_PI))) % width;
    sfIntRect rect1 = {offset_x, 0, width - offset_x, height};
    sfIntRect rect2 = {0, 0, SIZE_X - rect1.width, height};
    float pitch = player->pitch;

    if (offset_x < 0) {
        offset_x += width;
        rect1.left = offset_x;
    }
    sfSprite_setPosition(game->sprite, (sfVector2f){0, pitch});
    sfSprite_setTextureRect(game->sprite, rect1);
    sfSprite_setScale(game->sprite,
        (sfVector2f){1.0, (SIZE_Y / 2.0) / height});
    sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
    update_sky(game, rect1, rect2);
}

void draw_floor(sfRenderWindow *window, float pitch)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {SIZE_X, SIZE_Y / 2};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect,
        (sfVector2f){0, (SIZE_Y / 2.0) + pitch});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(0, 0, 0));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}
