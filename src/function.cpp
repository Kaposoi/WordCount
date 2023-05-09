//
// Created by 10496 on 2023/5/9.
//

#include "function.h"

void count_chars(FILE *file, long *char_count) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        (*char_count)++;
    }
}

void count_words(FILE *file, long *word_count) {
    char ch;
    int in_word = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') {
            if (in_word) {
                in_word = 0;
                (*word_count)++;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) {
        (*word_count)++;
    }
}