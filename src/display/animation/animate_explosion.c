/*
** EPITECH PROJECT, 2025
** animate explosion
** File description:
** animate the xplosion of the weapons
*/

#include "wolf.h"
#include "macros.h"
#include "weapons.h"

void update_explosion_anim(anim_t *anim, sfSprite *sprite, float delta_time)
{
    if (anim == NULL || sprite == NULL || anim->playing_ex == false)
        return;
    anim->elapsed += delta_time;
    if (anim->elapsed >= FRAMES_EX_TIME) {
        anim->elapsed = 0.0;
        anim->current_frame++;
        if (anim->current_frame >= NB_FRAMES_EX) {
            anim->current_frame = 0;
            anim->playing_ex = false;
            return;
        }
    }
    sfSprite_setTextureRect(sprite, anim->frames[anim->current_frame]);
}
