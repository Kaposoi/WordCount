#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: WordCount [parameter] [input_file_name]\n");
        return 1;
    }

    char *parameter = argv[1];
    char *input_file_name = argv[2];

    if (strcmp(parameter, "-c") != 0 && strcmp(parameter, "-w") != 0) {
        printf("Invalid parameter, please use -c or -w\n");
        return 1;
    }

    FILE *file = fopen(input_file_name, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    long count = 0;
    if (strcmp(parameter, "-c") == 0) {
        count_chars(file, &count);
        printf("the number of characters:%ld\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        count_words(file, &count);
        printf("the number of word:%ld\n", count);
    }

    fclose(file);
    return 0;
}
