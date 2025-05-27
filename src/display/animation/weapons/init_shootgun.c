/*
** EPITECH PROJECT, 2025
** animate_weapon
** File description:
** animate and init the weapons
*/

#include "player.h"
#include "weapons.h"

anim_t *init_shootgun_anim(void)
{
    anim_t *anim = malloc(sizeof(anim_t));

    if (anim == NULL)
        return NULL;
    anim->frame_count = NB_FRAMES_SHOOT;
    anim->frames = malloc(sizeof(sfIntRect) * NB_FRAMES_SHOOT);
    if (anim->frames == NULL)
        return NULL;
    for (int i = 0; i < NB_FRAMES_SHOOT; i++) {
        anim->frames[i].left = SHOOTGUN_LEFT;
        anim->frames[i].top = i * SHOOTGUN_TOP + i;
        anim->frames[i].width = SHOOTGUN_WIDTH;
        anim->frames[i].height = SHOOTGUN_HEIGHT;
    }
    anim->current_frame = 0;
    anim->frame_duration = FRAME_SHOOTGUN_TIME;
    anim->elapsed = 0.0;
    anim->playing = false;
    return anim;
}
