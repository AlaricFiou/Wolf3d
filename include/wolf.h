/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** the . h
*/

#ifndef WOLF_H_
    #define WOLF_H_
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include "game.h"
    #include "handle_enemies.h"

//SAVE SYSTEM

int open_save(player_t *player);
int create_save(player_t *player);

//INIT THE DATA

map_info_t *init_map(void);
player_t *init_player(map_info_t *map_info);
window_t *init_window(void);
sfSprite *init_sprite(sfTexture *texture);
sfTexture *init_texture(const char *path, const sfIntRect *area);

//HANDLE THE RAYCASTING

int is_wall(int x, int y, map_info_t *map_info);
float is_wall_hit(player_t *p, float angle, map_info_t *m);
void render_wall(window_t *game,
    size_t col, float height, int count_rays);

//HANDLE THE MAP

int tile_type_case(sfVector2f case_pos, map_info_t *map);
sfVector2f search_position(map_info_t *map_info, int id);
int is_correct_line(char *line);
int **open_map(char *path, map_info_t *map_info);
int get_map_infos(char *filepath, map_info_t *map_info);
char **str_to_word_array(const char *str, const char *separators);

//DISPLAY THE GAME ASSETS

void draw_floor(sfRenderWindow *window, float pitch);
void draw_sky(window_t *game, player_t *player);

//DISPLAY THE RAYCASTING

void cast_all_rays(window_t *game, player_t *player,
    map_info_t *map_info, float *z_buffer);
void draw_line(player_t *player, float rx, float ry, sfRenderWindow *w);

//FLASHLIGHT

void handle_flashlight(int count_rays,
    window_t *game, sfRectangleShape *wall);

//ANIMATE

anim_t *init_shootgun_anim(void);
void animate_ghoul_death(enemy_t *enemy, float delta_time);
void start_animation(anim_t *anim, sfSprite *sprite);
void update_weapon_anim(anim_t *anim, sfSprite *sprite, float delta_time);
void update_explosion_anim(anim_t *anim, sfSprite *sprite, float delta_time);

//HANDLE EVENTS

void shoot_bullet(player_t *player, enemy_manager_t *manager);
void handle_event(window_t *game, player_t *player,
    map_info_t *map_info, enemy_manager_t *enemy_manager);

//PLAYER

bool is_player_hit_by_enemy(enemy_t *enemy, player_t *player);
int damage_on_player(player_t *player);
void handle_player(player_t *player, map_info_t *map_info, float delta_time);

//WEAPONS

weapon_t *init_weapon_list(void);
void check_weapon(player_t *player, window_t *game);
void update_weapon_position(window_t *game, weapon_t *weapon);

//FREE THE DATA

void free_word_array(char **words);
void cleanup_dead_enemies(enemy_manager_t *manager);
void free_sprite(sfSprite *sprite, sfTexture *texture);
void destroy_game(window_t *game, enemy_manager_t *enemy_manager,
    player_t *player);

#endif /* !WOLF_H_ */
