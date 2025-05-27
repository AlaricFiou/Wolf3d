/*
** EPITECH PROJECT, 2025
** animate_weapon
** File description:
** animate the weapon animation
*/

#include "wolf.h"
#include "weapons.h"
#include "player.h"

void start_animation(anim_t *anim, sfSprite *sprite)
{
    anim->playing = true;
    anim->playing_ex = true;
    anim->current_frame = 0;
    anim->elapsed = 0;
    sfSprite_setTextureRect(sprite, anim->frames[0]);
}

void update_weapon_anim(anim_t *anim, sfSprite *sprite, float delta_time)
{
    if (anim == NULL || sprite == NULL || anim->playing == false)
        return;
    anim->elapsed += delta_time;
    if (anim->elapsed >= anim->frame_duration) {
        anim->elapsed = 0;
        anim->current_frame++;
        if (anim->current_frame >= anim->frame_count) {
            anim->current_frame = 0;
            anim->playing = false;
        }
    }
    sfSprite_setTextureRect(sprite, anim->frames[anim->current_frame]);
}
