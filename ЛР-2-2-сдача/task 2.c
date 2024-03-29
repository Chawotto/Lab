#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task 2.h"
#include "GenFunc.h"

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void processWord(char *word, int length) {
    size_t word_length = strlen(word);
    if (word_length > length) {
        reverseString(word);
    }
    printf("[%s] ", word);
}


void processFile(char *filename, int length) {
    FILE *file = fopen(filename, "r+");
    char *word = NULL;
    while ((word = readWordFromFile(file)) != NULL) {
        processWord(word, length);

        long wordLength = strlen(word);
        fseek(file, -wordLength, SEEK_CUR);

        fwrite(word, sizeof(char), wordLength, file);

        free(word);
        word = NULL;
        fseek(file, 1, SEEK_CUR);
    }

    fflush(file);
    fclose(file);

    printf("\n\n");
}

void task2(char *filename) {
    int length;
    printf("Введите длину слова: ");
    scanf("%d", &length);
    processFile(filename, length);
}