/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** split a string into words
*/

#include <string.h>
#include <stdlib.h>

static int is_separator(char c, const char *separators)
{
    for (int i = 0; separators[i] != '\0'; i++) {
        if (c == separators[i])
            return 1;
    }
    return 0;
}

static int count_words(const char *str, const char *separators)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_separator(str[i], separators) && !in_word) {
            count++;
            in_word = 1;
        }
        if (is_separator(str[i], separators))
            in_word = 0;
    }
    return count;
}

static char *allocate_word(const char *str, int start, int end)
{
    int len = end - start;
    char *word = malloc(len + 1);

    if (!word)
        return NULL;
    strncpy(word, &str[start], len);
    word[len] = '\0';
    return word;
}

static char **allocate_word_array(int word_count)
{
    char **tab = malloc(sizeof(char *) * (word_count + 1));

    if (tab == NULL)
        return NULL;
    tab[word_count] = NULL;
    return tab;
}

char **fill_word_array(const char *str, char **tab, const char *separators)
{
    int start = -1;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_separator(str[i], separators) && start == -1)
            start = i;
        if (is_separator(str[i], separators) && start != -1) {
            tab[j] = allocate_word(str, start, i);
            start = -1;
            j++;
        }
    }
    if (start != -1)
        tab[j] = allocate_word(str, start, strlen(str));
    return tab;
}

char **str_to_word_array(const char *str, const char *separators)
{
    int word_count = count_words(str, separators);
    char **tab = allocate_word_array(word_count);

    if (tab == NULL)
        return NULL;
    return fill_word_array(str, tab, separators);
}
