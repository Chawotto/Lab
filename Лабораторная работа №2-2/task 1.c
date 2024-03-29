//
// Created by alexe on 26.02.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task 1.h"
#include "GenFunc.h"

int countMaxWordSequence(FILE *file) {
    char *word = NULL;
    char *prev_word = NULL;
    int count = 0, max_count = 0;
    while ((word = readWordFromFile(file)) != NULL) {
        if (prev_word != NULL && strcmp(word, prev_word)==0) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
            }
            free(prev_word);
            prev_word = malloc(strlen(word) + 1);
            strcpy(prev_word, word);
            count = 1;
        }
        free(word);
    }

    if (count > max_count) {
        max_count = count;
    }

    free(prev_word);
    return max_count;
}

void task1(char *filename) {
    FILE *file = fopen(filename, "r");

    int max_count = countMaxWordSequence(file);

    printf("Количество слов в самой длинной последовательности повторяющихся слов: %d\n", max_count);

    fclose(file);
    printf("\n");
}