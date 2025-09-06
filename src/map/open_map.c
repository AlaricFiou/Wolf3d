#include <stdlib.h>
#include <stdio.h>
#include "wolf.h"

static int *convert_line_to_ints(char *str, int cols)
{
    char **words = str_to_word_array(str, ", \n");
    if (!words)
        return NULL;

    int *line = malloc(sizeof(int) * cols);
    if (!line) {
        free_word_array(words);
        return NULL;
    }

    for (int i = 0; i < cols; i++) {
        if (words[i])
            line[i] = atoi(words[i]);
        else
            line[i] = IS_WALL;
    }

    free_word_array(words);
    return line;
}

static int **create_map(FILE *file, int rows, int cols)
{
    int i = 0;
    size_t len = 0;
    __ssize_t nread;
    char *line = NULL;
    int **map = malloc(sizeof(int *) * rows);

    if (!map)
        return NULL;

    while (i < rows && (nread = getline(&line, &len, file)) != -1) {
        if (is_correct_line(line) == SUCCESS) {
            map[i] = convert_line_to_ints(line, cols);
            if (!map[i])
                break;
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

    if (!file) {
        fprintf(stderr, "Error: Unable to open the map file. Using the default map...\n");
        return NULL;
    }

    if (get_map_infos(path, map_info) != SUCCESS || map_info->rows <= 0 || map_info->cols <= 0) {
        fclose(file);
        return NULL;
    }

    rewind(file);
    map = create_map(file, map_info->rows, map_info->cols);
    fclose(file);
    return map;
}
