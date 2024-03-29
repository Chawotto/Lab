//
// Created by alexe on 18.02.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "func 1.h"

void task1(const char* filePath) {
    fillArray(filePath);
    printArray(filePath);
    int sum = calculateSum(filePath);
    printf("Сумма четных чисел в массиве: %d\n", sum);

    // Очистка файла после выполнения задачи
    FILE* file = fopen(filePath, "wb");
    fclose(file);
}

int calculateSum(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    fseek(file, 0, SEEK_END);
    int size = ftell(file) / sizeof(int);
    rewind(file);

    int* arr = (int*)malloc(size * sizeof(int));
    fread(arr, sizeof(int), size, file);

    int sum = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    free(arr);
    fclose(file);

    return sum;
}