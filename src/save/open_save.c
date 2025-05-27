/*
** EPITECH PROJECT, 2025
** open_save
** File description:
** open the save file and create one if not found
*/

#include "wolf.h"
#include <stdio.h>
#include <string.h>

static int get_infos(FILE *file, char *str, player_t *player)
{
    if (fscanf(file, "%s %d", str, &player->hp) != 2 ||
        strcmp(str, "#hp") != 0) {
        fclose(file);
        return FAILURE;
    }
    if (fscanf(file, "%s %ld", str, &player->score) != 2 ||
        strcmp(str, "#score") != 0) {
        fclose(file);
        return FAILURE;
    }
    if (fscanf(file, "%s %f %f", str, &player->x, &player->y) != 3 ||
        strcmp(str, "#position") != 0) {
        fclose(file);
        return FAILURE;
    }
    return SUCCESS;
}

int open_save(player_t *player)
{
    char str[STR_SIZE];
    FILE *file = fopen("game.save", "r");

    if (file == NULL || get_infos(file, str, player) == FAILURE)
        return FAILURE;
    fclose(file);
    return SUCCESS;
}

int create_save(player_t *player)
{
    FILE *file = fopen("game.save", "w");

    if (file == NULL)
        return FAILURE;
    fprintf(file, "#hp %d\n", player->hp);
    fprintf(file, "#score %ld\n", player->score);
    fprintf(file, "#position %.2f %.2f\n", player->x, player->y);
    fclose(file);
    return SUCCESS;
}
