/*
** EPITECH PROJECT, 2025
** struct
** File description:
** contain the struct and define
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "macros.h"
    #include "weapons.h"
    #include <stdbool.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

// CONTAIN THE STRUCT USED FOR THE GAME LOOP

typedef struct ray_s {
    int side;
    int step_y;
    int step_x;
    float side_y;
    float side_x;
    float delta_y;
    float delta_x;
    float ray_dir_y;
    float ray_dir_x;
} ray_t;

typedef struct map_info_s {
    int rows;
    int cols;
    int **map;
    ray_t ray;
    float dist;
} map_info_t;

typedef struct effect_s {
    sfMusic *music;
    sfSound *sound;
    bool flashlight;
    sfSoundBuffer *sound_buffer;
} effect_t;

typedef struct player_s {
    int hp;
    float x;
    float y;
    float angle;
    float pitch;
    size_t score;
    weapon_t *weapon;
    float invincibility_timer;
} player_t;

typedef struct window_s {
    sfView *view;
    sfEvent event;
    sfClock *clock;
    sfTime elapsed;
    effect_t effect;
    sfSprite *sprite;
    float delta_time;
    sfTexture *texture;
    map_info_t *map_info;
    player_t *player;
    sfRenderWindow *window;
}window_t;

#endif /* !GAME_H_ */
