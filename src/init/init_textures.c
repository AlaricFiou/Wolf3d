/*
** EPITECH PROJECT, 2025
** init_textures
** File description:
** init the textures
*/

#include "wolf.h"

sfSprite *init_sprite(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL || texture == NULL)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfTexture *init_texture(const char *path, const sfIntRect *area)
{
    sfTexture *texture = sfTexture_createFromFile(path, area);

    if (texture == NULL)
        return NULL;
    return texture;
}
