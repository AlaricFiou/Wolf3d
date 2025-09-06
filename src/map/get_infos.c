#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "wolf.h"
#include <macros.h>

int is_numeric(const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]))
            return FAILURE;
    }
    return SUCCESS;
}

int is_correct_line(char *line)
{
    if (line == NULL || line[0] == '\0' || line[0] == '#' || line[0] == '\n')
        return FAILURE;

    char **words = str_to_word_array(line, ", \n");
    if (!words)
        return FAILURE;

    for (int i = 0; words[i]; i++) {
        if (is_numeric(words[i]) == FAILURE) {
            free_word_array(words);
            return FAILURE;
        }
    }
    free_word_array(words);
    return SUCCESS;
}

static int count_valid_words(char **words)
{
    int count = 0;
    for (int i = 0; words[i] != NULL; i++) {
        if (is_numeric(words[i]) == SUCCESS)
            count++;
    }
    return count;
}

static void update_infos(char *line, int *rows, int *cols)
{
    char **words;

    if (is_correct_line(line) == FAILURE)
        return;

    words = str_to_word_array(line, ", \n");
    if (!words)
        return;

    int current_cols = count_valid_words(words);

    if (*cols == 0)
        *cols = current_cols;
    else if (current_cols != *cols)
        fprintf(stderr, "Warning: ligne %d has a wrong columns size (%d vs %d).\n", *rows + 1, current_cols, *cols);

    (*rows)++;
    free_word_array(words);
}

int get_map_infos(char *filepath, map_info_t *map_info)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    __ssize_t nread = 0;
    int rows = 0;
    int cols = 0;

    if (!file)
        return OPEN_FAILURE;

    while ((nread = getline(&line, &len, file)) != -1) {
        update_infos(line, &rows, &cols);
    }

    free(line);
    fclose(file);
    map_info->rows = rows;
    map_info->cols = cols;
    return SUCCESS;
}
