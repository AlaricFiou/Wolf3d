/*
** EPITECH PROJECT, 2025
** raycasting
** File description:
** the algorithm of raycasting
*/

#include <stdbool.h>
#include <math.h>
#include "wolf.h"

static sfRectangleShape *create_wall(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfTexture *texture =
        sfTexture_createFromFile("assets/walls/brick_wall.png", NULL);

    if (texture == NULL) {
        fprintf(stderr, "Error: failed to load wall texture\n");
        return NULL;
    }
    sfRectangleShape_setTexture(shape, texture, false);
    return shape;
}

void render_wall(window_t *game,
    size_t col, float height, int count_rays)
{
    static sfRectangleShape *wall = NULL;
    float offset = (SIZE_Y - height) / 2 + game->player->pitch;
    sfVector2f size = {1, height};
    sfVector2f pos = {col, offset};

    if (wall == NULL)
        wall = create_wall();
    sfRectangleShape_setSize(wall, size);
    sfRectangleShape_setPosition(wall, pos);
    handle_flashlight(count_rays, game, wall);
    if (game->window != NULL)
        sfRenderWindow_drawRectangleShape(game->window, wall, NULL);
}

void draw_line(player_t *p, float rx,
    float ry, sfRenderWindow *window)
{
    sfVertex line[] = {
        {{p->x, p->y}, sfWhite, {0, 0}},
        {{rx, ry}, sfWhite, {0, 0}}
    };

    window = NULL;
    if (window != NULL)
        sfRenderWindow_drawPrimitives(window, line, 2, sfLines, NULL);
}
