/*
** EPITECH PROJECT, 2025
** free
** File description:
** free the memory used in the programe
*/

#include <stdlib.h>

void free_word_array(char **words)
{
    for (size_t i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);
}
