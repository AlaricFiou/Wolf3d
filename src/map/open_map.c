/*
** EPITECH PROJECT, 2025
** open map
** File description:
** open the file map and create the map
*/

#include <stdlib.h>
#include <stdio.h>
#include "wolf.h"

static int *convert_line_to_ints(char *str, int cols)
{
    char **words = NULL;
    int *line = malloc(sizeof(int) * cols);

    if (line == NULL)
        return NULL;
    words = str_to_word_array(str, ", \n");
    if (words == NULL)
        return NULL;
    for (int i = 0; i < cols && words[i] != NULL; i++) {
        line[i] = atoi(words[i]);
    }
    free_word_array(words);
    return line;
}

static int **create_map(FILE *file, int rows, int cols)
{
    int i = 0;
    size_t len = 0;
    char *line = NULL;
    __ssize_t nread = 0;
    int **map = malloc(sizeof(int *) * rows);

    if (map == NULL)
        return NULL;
    while (i < rows) {
        nread = getline(&line, &len, file);
        if (nread == -1)
            break;
        if (is_correct_line(line) == SUCCESS) {
            map[i] = convert_line_to_ints(line, cols);
            i++;
        }
    }
    free(line);
    return map;
}

int **open_map(char *path, map_info_t *map_info)
{
    FILE *file = fopen(path, "r");
    int **map = NULL;

    if (file == NULL) {
        fprintf(stderr,
            "Error: enable to open the map file. Unsing the default map...\n");
        return NULL;
    }
    if (get_map_infos(path, map_info) != SUCCESS ||
        file == NULL || map_info == NULL) {
        fclose(file);
        return NULL;
    }
    if (map_info->rows <= 0 || map_info->cols <= 0) {
        fclose(file);
        return NULL;
    }
    map = create_map(file, map_info->rows, map_info->cols);
    fclose(file);
    return map;
}
