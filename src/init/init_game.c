/*
** EPITECH PROJECT, 2025
** init
** File description:
** init the values
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wolf.h"

static void init_sound(effect_t *effect)
{
    effect->sound_buffer = sfSoundBuffer_createFromFile(SOUND_SHOOTGUN_PATH);
    if (effect->sound_buffer == NULL) {
        return;
    }
    effect->sound = sfSound_create();
    if (effect->sound == NULL) {
        sfSoundBuffer_destroy(effect->sound_buffer);
        return;
    }
    sfSound_setBuffer(effect->sound, effect->sound_buffer);
}

static void init_music(effect_t *effect)
{
    effect->music = sfMusic_createFromFile(MUSIC_PATH);
    if (effect->music != NULL) {
        sfMusic_setVolume(effect->music, MUSIC_VOLUME);
        sfMusic_setLoop(effect->music, sfTrue);
        sfMusic_play(effect->music);
    }
}

static effect_t init_effect(void)
{
    effect_t effect = {0};

    init_music(&effect);
    init_sound(&effect);
    return effect;
}

window_t *init_window(void)
{
    sfVector2u size = {0, 0};
    sfVideoMode mode = {SIZE_X, SIZE_Y, 32};
    window_t *game = malloc(sizeof(window_t));

    if (game == NULL)
        return NULL;
    game->texture = init_texture("assets/background/sky.png", NULL);
    sfTexture_setSmooth(game->texture, sfFalse);
    game->sprite = init_sprite(game->texture);
    sfSprite_setTexture(game->sprite, game->texture, sfTrue);
    game->window = sfRenderWindow_create(mode, "SFML window",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->clock = sfClock_create();
    game->effect = init_effect();
    game->delta_time = 0;
    size = sfRenderWindow_getSize(game->window);
    game->view = sfView_createFromRect((sfFloatRect){0, 0, size.x, size.y});
    sfRenderWindow_setView(game->window, game->view);
    return game;
}
