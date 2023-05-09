//
// Created by Remiliaium on 2023/5/9.
//

#include <stdio.h>
#include <assert.h>
#include "../src/function.h"

void test_count_chars() {
    FILE *file = fopen("test_chars.txt", "w");
    fprintf(file, "hello, world, s, c, p. a");
    fclose(file);

    file = fopen("test_chars.txt", "r");
    long char_count = 0;
    count_chars(file, &char_count);
    fclose(file);

    assert(char_count == 24);

    printf("test count chars passed\n");
}

void test_count_words() {
    FILE *file = fopen("test_words.txt", "w");
    fprintf(file, "that just a best, choice\nyou think it??");
    fclose(file);
    
    file = fopen("test_words.txt", "r");
    long word_count = 0;
    count_words(file, &word_count);

    fclose(file);
    assert(word_count == 8);

    printf("test count words passed\n");
}

void activate_test() {
    test_count_chars();
    test_count_words();
}

int main() {
    activate_test();
}