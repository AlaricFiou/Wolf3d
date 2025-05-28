/*
** EPITECH PROJECT, 2025
** shotgun
** File description:
** init the shotgun weapon
*/

#include "wolf.h"
#include "macros.h"
#include "weapons.h"
#include "weapon_features.h"

static anim_t *init_shotgun_anim(void)
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

weapon_t *init_shotgun(void)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    if (weapon == NULL)
        return NULL;
    weapon->texture = init_texture(PATH_SHOOTGUN, NULL);
    weapon->sprite = init_sprite(weapon->texture);
    weapon->ex_texture = init_texture(PATH_EX, NULL);
    weapon->ex_sprite = init_sprite(weapon->ex_texture);
    weapon->shoot_anim = init_shotgun_anim();
    weapon->explosion_anim = init_explosion();
    weapon->next = NULL;
    weapon->state = WEAPON_IDLE;
    if (weapon->shoot_anim)
        sfSprite_setTextureRect(weapon->sprite, weapon->shoot_anim->frames[0]);
    return weapon;
}
