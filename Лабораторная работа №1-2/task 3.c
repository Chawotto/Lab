//
// Created by alexe on 18.02.2024.
//
#include <stdio.h>
#include "task 3.h"
#include "func.h"

int isPrime(int num) {
    if(num <= 1) return 0;
    if(num == 2) return 1;
    if(num % 2 == 0) return 0;
    for(int i = 3; i * i <= num; i += 2) {
        if(num % i == 0) return 0;
    }
    return 1;
}

void sortPrimes(const char* filePath) {
    FILE* file = fopen(filePath, "rb+");
    fseek(file, 0, SEEK_END);
    int size = ftell(file) / sizeof(int);
    rewind(file);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int num1, num2;
            fseek(file, j * sizeof(int), SEEK_SET);
            fread(&num1, sizeof(int), 1, file);
            fread(&num2, sizeof(int), 1, file);

            int isNum1Prime = isPrime(num1);
            int isNum2Prime = isPrime(num2);

            if ((isNum1Prime && num1 < num2) || (!isNum1Prime && isNum2Prime) || (num1 < num2)) {
                fseek(file, j * sizeof(int), SEEK_SET);
                fwrite(&num2, sizeof(int), 1, file);
                fwrite(&num1, sizeof(int), 1, file);
            }
        }
    }

    fclose(file);
}

void removeComposites(const char* filePath) {
    const char* tempFilePath = "temp.bin";
    FILE* file = fopen(filePath, "rb");
    FILE* tempFile = fopen(tempFilePath, "wb+");

    int num;

    while (fread(&num, sizeof(int), 1, file) != 0) {
        if (isPrime(num)) {
            fwrite(&num, sizeof(int), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filePath);
    rename(tempFilePath, filePath);
}

void task3(const char* filePath) {
    fillArray(filePath);

    printf("Исходный массив:\n");
    printArray(filePath);

    sortPrimes(filePath);
    removeComposites(filePath);

    printf("Массив после сортировки простых чисел и удаления составных чисел:\n");
    printArray(filePath);
}