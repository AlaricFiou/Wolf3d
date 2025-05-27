/*
** EPITECH PROJECT, 2025
** player
** File description:
** contain the player data
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include "wolf.h"
    #include <SFML/Window/Keyboard.h>
    #define PLAYER_ID 2

// INIT THE PLAYER'S FUNCTION

typedef void (*action_func_t)(player_t *, map_info_t *);

// HANDLE THE PLAYER MOVEMENT

void move_left(player_t *player, map_info_t *map_info);
void move_right(player_t *player, map_info_t *map_info);
void look_up(player_t *player, map_info_t *map_info);
void look_down(player_t *player, map_info_t *map_info);
void rotate_left(player_t *player, map_info_t *map_info);
void rotate_right(player_t *player, map_info_t *map_info);
void move_forward(player_t *player, map_info_t *map_info);
void move_backward(player_t *player, map_info_t *map_info);

void special_case(player_t *player);

typedef struct control_s {
    sfKeyCode key;
    action_func_t action;
} control_t;

static const control_t controls[] = {
    {sfKeyQ, move_left},
    {sfKeyD, move_right},
    {sfKeyZ, move_forward},
    {sfKeyS, move_backward},
    {sfKeyLeft, rotate_left},
    {sfKeyRight, rotate_right},
    {sfKeyUp, look_up},
    {sfKeyDown, look_down},
};

#endif /* !PLAYER_H_ */
