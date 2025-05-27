/*
** EPITECH PROJECT, 2025
** get_infos
** File description:
** return the number of lines and col in a file
*/

#include <stdio.h>
#include "wolf.h"
#include <ctype.h>
#include <stdlib.h>
#include <macros.h>

int is_correct_line(char *line)
{
    if (line == NULL || line[0] == '\0' || line[0] == '#' || line[0] == '\n')
        return FAILURE;
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i]) == FAILURE) {
            return FAILURE;
        }
    }
    return SUCCESS;
}

static int count_valid_words(char **words)
{
    int count = 0;

    for (size_t i = 0; words[i] != NULL; i++) {
        if (isdigit(words[i][0]))
            count++;
    }
    return count;
}

static void update_infos(char *line, int *rows, int *cols)
{
    char **words;

    if (is_correct_line(line) == FAILURE)
        return;
    if ((*rows) == 0) {
        words = str_to_word_array(line, ", \n");
        if (words != NULL) {
            (*cols) = count_valid_words(words);
            free_word_array(words);
        }
    }
    (*rows)++;
}

int get_map_infos(char *filepath, map_info_t *map_info)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    __ssize_t nread = 0;
    int rows = 0;
    int cols = 0;

    if (file == NULL)
        return OPEN_FAILURE;
    while (1) {
        nread = getline(&line, &len, file);
        if (nread == -1)
            break;
        update_infos(line, &rows, &cols);
    }
    free(line);
    fclose(file);
    map_info->rows = rows;
    map_info->cols = cols;
    return SUCCESS;
}
