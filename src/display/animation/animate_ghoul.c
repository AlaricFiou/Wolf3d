/*
** EPITECH PROJECT, 2025
** animate_ghoul
** File description:
** animate the ghoul enemy because the frame are not the same
*/

#include "handle_enemies.h"

static void update_enemy(enemy_t *enemy, int left,
    const int death_widths[8], int current_frame)
{
    enemy->rect.left = left;
    enemy->rect.top = GHOUL_DEATH_TOP;
    enemy->rect.width = death_widths[current_frame];
    enemy->rect.height = GHOUL_DEATH_HEIGHT;
}

void animate_ghoul_death(enemy_t *enemy, float delta_time)
{
    int left = 0;
    const int death_widths[8] = {38, 38, 38, 50, 49, 53, 62, 42};

    if (enemy == NULL || enemy->sprite == NULL)
        return;
    enemy->timer += delta_time;
    if (enemy->timer < GHOUL_DEATH_SPEED)
        return;
    enemy->timer = 0.0;
    left = GHOUL_LEFT_IDLE;
    for (int i = 0; i < enemy->death_frame; i++) {
        left += death_widths[i] + 2;
    }
    update_enemy(enemy, left, death_widths, enemy->death_frame);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    enemy->death_frame++;
    if (enemy->death_frame >= GHOUL_DEATH_FRAMES) {
        enemy->death_frame = GHOUL_DEATH_FRAMES - 1;
        enemy->state = ENEMY_DEAD_ANIM_FINISHED;
    }
}
