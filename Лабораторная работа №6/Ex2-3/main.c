#include <stdio.h>
#include <process.h>
#include "Functions.h"

//3. В прямоугольной матрице размером выполнить сортировку строк по убыванию
//количества четных элементов методом вставок.

int main() {
    system("chcp 65001");
    int choice, rows, cols;
    int* even;
    printf("1) Ввод вручную\n2) Тест\n");
    scanf("%d", &choice);
    int **array;
    switch (choice) {

        case 1 :
            printf("Введите количество строк: ");
            scanf("%d", &rows);
            printf("Введите количество столбцов: ");
            scanf("%d", &cols);
            array = arr(rows, cols);
            printf("Матрица:\n");
            output(array, rows, cols);
            break;


        case 2 :
            rows = 4;
            cols = 5;
            array = test_array(rows, cols);
            printf("Массив:\n");
            output(array, rows, cols);
            break;

        default:

            printf("Неверное значение\n");
            break;
    }

    even = even_count(array, rows, cols);
    array = insert_sort (array, rows, cols, even);
    printf("\n");
    output (array, rows, cols);

return 0;
}

