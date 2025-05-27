/*
** EPITECH PROJECT, 2025
** flashlight
** File description:
** handle the flashlight
*/

#include "wolf.h"

static void update_intensity(int *intensity)
{
    if (intensity > MAX_LIGHT)
        intensity = MAX_LIGHT;
}

void handle_flashlight(int count_rays,
    window_t *game, sfRectangleShape *wall)
{
    int intensity = 0;
    int color = abs(count_rays - MIDDLE);

    if (color >= DARK_RAYS) {
        sfRectangleShape_setFillColor(wall, sfColor_fromRGB(DARK, DARK, DARK));
    } else if (game->effect.flashlight == true) {
        intensity = DARK + DARK_RAYS - color;
        update_intensity(&intensity);
        sfRectangleShape_setFillColor(wall,
            sfColor_fromRGB(intensity, intensity, intensity));
    }
}
