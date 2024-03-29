//
// Created by alexe on 19.12.2023.
//

#include <stdlib.h>
#include <stdio.h>

int** arr(int rows, int cols) {
    // Выделение памяти под массив
    int** array = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }
    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    return array;
}

int** test_array (int rows, int cols){
    int** array = (int**)malloc( rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }
    int test_array[4][5] = {{ 1 ,6 ,5 ,9, 8} ,
                           { 6 ,3 ,1 ,5, 7} ,
                           { 4 ,2 ,6 ,1, 4 } ,
                           { 2 ,4 ,3 ,6, 3}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = test_array[i][j];
        }
    }
    return array;
}