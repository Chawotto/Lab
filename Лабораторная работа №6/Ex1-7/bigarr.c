//
// Created by alexe on 17.12.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* bigarr(int n) {
    int *array = (int *) malloc((n) * sizeof(int));
    int *bigarray = (int *) malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        bigarray[i] = rand() % 200001 - 10000;  // Генерируем случайное число от -10000 до 10000
    }
    for (int i = 0; i < n; i++) {
        array[i] = bigarray[i];
    }
    free(bigarray); // Освобождаем память, выделенную для временного bigarray
    return array;
}

int* sorted_bigarr (int n){
    int *array = (int *) malloc((n + 1) * sizeof(int));
    int sortbigarray [n];
    for (int i = 0; i < n; i++) {
        sortbigarray[i] = i + 1-5000;
    }
    for (int i = 0; i < n; i++) {
        array[i] = sortbigarray[i];
    }
    return array;
}
