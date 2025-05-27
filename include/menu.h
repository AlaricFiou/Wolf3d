/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include "game.h"
    #include <stdbool.h>

typedef struct buttons_s {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    // button_func function;
} buttons_t;

#endif /* !MENU_H_ */
