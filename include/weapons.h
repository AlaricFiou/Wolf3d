/*
** EPITECH PROJECT, 2025
** weapons
** File description:
** handle the weapons
*/

#ifndef WEAPONS_H_
    #define WEAPONS_H_
    #include <stdlib.h>
    #include <stdbool.h>

typedef enum {
    WEAPON_IDLE,
    WEAPON_SHOOTING,
    WEAPON_EXPLODING
} weapon_state_t;

typedef struct anim_s {
    sfIntRect *frames;
    int frame_count;
    int current_frame;
    float frame_duration;
    float elapsed;
    bool playing;
    bool playing_ex;
} anim_t;

typedef struct weapon_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *ex_sprite;
    sfTexture *ex_texture;
    struct weapon_s *next;
    anim_t *shoot_anim;
    anim_t *explosion_anim;
    weapon_state_t state;
} weapon_t;

weapon_t *init_shootgun(void);

typedef struct weapon_factory_s {
    const char *name;
    weapon_t *(*init_func)(void);
} weapon_factory_t;

static const weapon_factory_t weapon_factory[] = {
    {"shootgun", &init_shootgun},
    {NULL, NULL}
};

#endif /* !WEAPONS_H_ */
