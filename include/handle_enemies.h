/*
** EPITECH PROJECT, 2025
** handle_enemies
** File description:
** handle the enemies
*/

#ifndef HANDLE_ENEMIES_H_
    #define HANDLE_ENEMIES_H_
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "enemies_status.h"
    #include "game.h"
    #define ANIMATION_SPEED 0.2

typedef enum {
    ENEMY_IDLE,
    ENEMY_MOVE,
    ENEMY_ATTACK,
    ENEMY_PAIN,
    ENEMY_DEAD,
    ENEMY_DEAD_ANIM_FINISHED
} enemy_state_t;

typedef struct enemy_s {
    int hp;
    int id;
    float z;
    int frames;
    float timer;
    float angle;
    float speed;
    size_t score;
    int start_left;
    sfIntRect rect;
    sfSprite *sprite;
    int death_frame;
    sfTexture *texture;
    sfVector2f position;
    enemy_state_t state;
} enemy_t;

typedef struct enemy_manager_s {
    size_t count;
    enemy_t *enemies[MAX_ENEMIES];
} enemy_manager_t;

//INIT

enemy_manager_t *init_enemy_manager(map_info_t *map_info);

//ANIMATE

//GHOUL
void handle_ghoul_pain(enemy_t *enemy, float delta_time);

void animate_enemy(enemy_t *enemy, float delta_time);
void move_enemy_towards_player(enemy_t *enemy, player_t *player,
    float dt, map_info_t *map);

//DISPLAY

void handle_ennemies(window_t *game, enemy_manager_t *enemy_manager,
    player_t *player, float *z_buffer);
void draw_enemy_3d(sfRenderWindow *window, player_t *player,
    enemy_t *enemy, float *z);
void draw_all_enemies(enemy_manager_t *manager,
    sfRenderWindow *window, player_t *player, float *z_buffer);
void update_all_enemies(enemy_manager_t *manager, player_t *player,
    float delta_time, map_info_t *map);

#endif /* !HANDLE_ENEMIES_H_ */
