//
// Created by alexe on 19.03.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "GenFunc.h"

char* readWordFromFile(FILE* file) {
    char* word = NULL;
    int result;

    result = fscanf(file, "%*[^a-zA-Z]");
    if (result == EOF) {
        return NULL;
    }

    result = fscanf(file, "%m[a-zA-Z]", &word);
    if (result == 1) {
        return word;
    } else {
        free(word);
        return NULL;
    }
}

void printFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    char *word = NULL;
    while (fscanf(file, "%ms", &word) != EOF) {
        printf("%s ", word);
        free(word);
    }
    printf("\n");
    fclose(file);
}