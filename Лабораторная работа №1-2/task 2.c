//
// Created by alexe on 18.02.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "func.h"

void task2(const char* filePath) {
    fillArray(filePath);
    printf("Исходный массив:\n");
    printArray(filePath);

    FILE* file = fopen(filePath, "rb+");
    fseek(file, 0, SEEK_END);
    int size = ftell(file) / sizeof(int);
    rewind(file);

    int min = INT_MAX, lastMinIndex = -1;
    for(int i = 0; i < size; i++) {
        int current;
        fread(&current, sizeof(int), 1, file);
        if(current <= min) {
            min = current;
            lastMinIndex = i;
        }
    }

    ftruncate(fileno(file), (lastMinIndex + 1) * sizeof(int));
    fclose(file);

    printf("Массив после удаления элементов:\n");
    printArray(filePath);
}