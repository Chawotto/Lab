//
// Created by alexe on 18.02.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArrayRandomly(int* arr, int size) {
    srand(time(0));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void fillArrayManually(int* arr, int size) {
    printf("Введите элементы массива:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void writeToFile(const char* filePath, int* arr, int size) {
    FILE* file = fopen(filePath, "wb");
    fwrite(arr, sizeof(int), size, file);
    fclose(file);
}

void fillArray(const char* filePath){
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    int choice;
    printf("Выберите способ заполнения массива (1 - случайно, 2 - вручную): ");
    scanf("%d", &choice);

    if(choice == 1) {
        fillArrayRandomly(arr, size);
    } else if(choice == 2) {
        fillArrayManually(arr, size);
    } else {
        printf("Неверный выбор!\n");
        free(arr);
        return;
    }
    writeToFile(filePath, arr, size);
    free(arr);
    FILE* file = fopen(filePath, "rb+");
    rewind(file);
    fclose(file);
}

void printArray(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    fseek(file, 0, SEEK_END);
    int size = ftell(file) / sizeof(int);
    rewind(file);

    int* arr = (int*)malloc(size * sizeof(int));
    fread(arr, sizeof(int), size, file);

    printf("Элементы массива:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    fclose(file);
}
