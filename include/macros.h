/*
** EPITECH PROJECT, 2025
** macros
** File description:
** the macros used in the project
*/

#ifndef MACROS_H_
    #define MACROS_H_

    //MAP SIZE

    #define SIZE_X 1920
    #define SIZE_Y 1080
    #define DEFAULT_MAP 8

    //RAYCASTING VARIABLES

    #define IS_WALL 1
    #define IS_EMPTY 0
    #define SHORTER_PATH 1
    #define LONGER_PATH -1
    #define MY_PI 3.14159265
    #define NO_WALL_FOUND 2147483647
    #define FOV (60.0 * (MY_PI / 180.0))

    //MAP VARIABLES

    #define MAP_WIDTH 24
    #define TILE_SIZE 64
    #define MAP_HEIGHT 24
    #define NUM_RAYS SIZE_X

    //PLAYER FEATURES

    #define MOVE_SPEED 2
    #define ROT_SPEED 0.03

    //PARSING MAP

    #define SUCCESS 0
    #define FAILURE 84
    #define STR_SIZE 64
    #define OPEN_FAILURE -1

    //EFFECTS

    #define MUSIC_VOLUME 20
    #define MUSIC_PATH "assets/music/doom.mp3"
    #define SOUND_SHOOTGUN_PATH "assets/sound/shootgun_sound.mp3"

    //WEAPONS

    #define NB_FRAMES_EX 7
    #define FRAMES_EX_TIME 0.05
    #define WEAPON_POS_HEIGHT 0.0

    #define EX_SIZE 15
    #define WEAPON_EX_TOP 10
    #define WEAPON_EX_LEFT 10
    #define WEAPON_EX_WIDTH 31
    #define WEAPON_EX_HEIGHT 21

    #define BULLET_DAMAGE 5
    #define SHOOTGUN_LEFT 72
    #define SHOOTGUN_TOP 162
    #define SHOOTGUN_SIZE 4.1
    #define NB_FRAMES_SHOOT 8
    #define BULLET_RADIUS 20.0
    #define SHOOTGUN_WIDTH 232
    #define SHOOTGUN_HEIGHT 161
    #define BULLET_RANGE 1000.0
    #define FRAME_SHOOTGUN_TIME 0.1

    //WALL ASSETS

    #define DARK 50
    #define MAX_LIGHT 255
    #define DARK_RAYS 285
    #define MIDDLE 640
    #define MIDDLE_R 895
    #define LIT_RAYS 100
    #define FADE_GAP DARK_RAYS - LIT_RAYS
    #define TEXTURE_WALL "assets/walls/wall.png"

    //PLAYER

    #define PITCH_SPEED 5
    #define MAX_ANGLE_UP 0
    #define MAX_ANGLE_DOWN 350
    #define PLAYER_HP 3
    #define PLAYER_DEAD -1
    #define PLAYER_INVINCIBILITY 2

#endif /* !MACROS_H_ */
