/*
** EPITECH PROJECT, 2025
** init_weapon
** File description:
** init the weapons
*/

#include "wolf.h"
#include <string.h>
#include "weapons.h"
#include "weapon_features.h"

anim_t *init_explosion(void)
{
    anim_t *anim = malloc(sizeof(anim_t));

    if (anim == NULL)
        return NULL;
    anim->frame_count = NB_FRAMES_EX;
    anim->frames = malloc(sizeof(sfIntRect) * NB_FRAMES_EX);
    if (anim->frames == NULL)
        return NULL;
    for (int i = 0; i < NB_FRAMES_EX; i++) {
        anim->frames[i].left = i * (WEAPON_EX_WIDTH + 1);
        anim->frames[i].top = 0;
        anim->frames[i].width = WEAPON_EX_WIDTH;
        anim->frames[i].height = WEAPON_EX_HEIGHT;
    }
    anim->current_frame = 0;
    anim->frame_duration = FRAMES_EX_TIME;
    anim->elapsed = 0.0;
    anim->playing = false;
    anim->playing_ex = false;
    return anim;
}

weapon_t *init_shootgun(void)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    if (weapon == NULL)
        return NULL;
    weapon->texture = init_texture(PATH_SHOOTGUN, NULL);
    weapon->sprite = init_sprite(weapon->texture);
    weapon->ex_texture = init_texture(PATH_EX, NULL);
    weapon->ex_sprite = init_sprite(weapon->ex_texture);
    weapon->shoot_anim = init_shootgun_anim();
    weapon->explosion_anim = init_explosion();
    weapon->next = NULL;
    weapon->state = WEAPON_IDLE;
    if (weapon->shoot_anim)
        sfSprite_setTextureRect(weapon->sprite, weapon->shoot_anim->frames[0]);
    return weapon;
}

static weapon_t *init_weapon_by_name(const char *name)
{
    for (int i = 0; weapon_factory[i].name != NULL; i++) {
        if (strcmp(name, weapon_factory[i].name) == 0)
            return weapon_factory[i].init_func();
    }
    return NULL;
}

weapon_t *init_weapon_list(void)
{
    weapon_t *head = NULL;
    weapon_t *current = NULL;
    weapon_t *new_weapon = NULL;

    for (size_t i = 0; i < NB_WEAPONS; i++) {
        new_weapon = init_weapon_by_name(tab_weapons[i]);
        if (new_weapon == NULL)
            continue;
        new_weapon->next = NULL;
        if (head == NULL) {
            head = new_weapon;
            current = new_weapon;
        } else {
            current->next = new_weapon;
            current = new_weapon;
        }
    }
    return head;
}
