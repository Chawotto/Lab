#include <stdlib.h>
#include <stdio.h>
#include "task3.h"

void task3 (int argc, char** argv) {

    int N = atoi(argv[2]);

    // Выделение памяти для массива указателей на строки
    char** arr = (char**)malloc(N * sizeof(char*));

    // Копирование аргументов командной строки в массив строк
    for (int i = 0; i < N; i++) {
        char* str = argv[i + 3];
        int len = 0;
        while (str[len] != '\0')
            len++;
        arr[i] = (char*)malloc((len + 3) * sizeof(char));
        for (int j = 0; j <= len; j++)
            arr[i][j] = str[j];
    }

    // Сортировка слиянием
    mergeSort(arr, 0, N - 1);

    // Вывод отсортированного массива строк
    printf("Sorted strings:\n");
    for (int i = 0; i < N; i++)
        printf("%s\n", arr[i]);

    // Освобождение памяти
    for (int i = 0; i < N; i++)
        free(arr[i]);

    free(arr);
    exit(1);
}