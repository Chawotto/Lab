#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

//Эталон
//Исходный массив: 12 -2 7 -4 5 6 3 -8 9 24
//Отсортированный слиянием массив: 3 -2 5 -4 6 7 9 -8 12 24
//Отсортированный пузырьком массив: 3 -2 5 -4 6 7 9 -8 12 24
//Заранее отсортированный исходный массив: 3 -2 5 -4 6 7 9 -8 12 24
//Заранее отсортированный + сортированный в обратном порядке слиянием: 24 -2 12 -4 9 7 6 -8 5 3
//Заранее отсортированный + сортированный в обратном порядке пузырьком: 24 -2 12 -4 9 7 6 -8 5 3
//Время сортировки случайного массива алгоритмом слияния (мс): ---
//Время сортировки случайного массива алгоритмом пузырька (мс): ---
//Время сортировки заранее отсортированного массива алгоритмом слияния (мс): ---
//Время сортировки заранее отсортированного массива алгоритмом пузырька (мс): ---
//Время сортиовки заранее отсортированного массива, сортированного в обратном порядке слиянием (мс): ---
//Время сортировки заранее отсортированного массива, сортированного в обратном порядке пузырьком (мс): ---

int main(){
    system("chcp 65001");
    //Работа с малым массивом:
    int n = 10;
    int* arr = test(n);

    printf("Исходный массив: ");
    output (arr, n);

    printf("Отсортированный слиянием массив: ");
    merge_sort_positive_elements( arr, n);
    output (arr, n);
    free(arr);
    arr = test(n);

    printf("Отсортированный пузырьком массив: ");
    buble_sort_positive_elements ( arr, n);
    output (arr, n);
    free(arr);
    arr = sorted_arr (n);

    printf("Заранее отсортированный исходный массив: ");
    output (arr, n);

    printf("Заранее отсортированный + сортированный в обратном порядке слиянием: ");
    reverse_merge_sort_positive_elements(arr, n);
    output (arr, n);
    free(arr);
    arr = sorted_arr (n);

    printf("Заранее отсортированный + сортированный в обратном порядке пузырьком: ");
    reverse_buble_sort_positive_elements(arr, n);
    output (arr, n);
    free(arr);


    //Работа с большим массивом

    n = 100000;
    arr = bigarr(n);
    time_manage(arr, n, merge_sort_positive_elements, "сортировки случайного массива слиянием ");
    free(arr);

    n = 20000;
    arr = bigarr(n);
    time_manage(arr, n, buble_sort_positive_elements, "сортировки случайного массива пузырьком ");
    free(arr);

    n = 60000;
    arr = sorted_bigarr(n);
    time_manage(arr, n, merge_sort_positive_elements, "сортировки заранее отсортированного массива слиянием ");
    free(arr);

    n = 20000;
    arr = sorted_bigarr(n);
    time_manage(arr, n, buble_sort_positive_elements, "сортировки заранее отсортированного массива пузырьком ");
    free (arr);

    n = 100000;
    arr = sorted_bigarr(n);
    time_manage(arr, n, reverse_merge_sort_positive_elements, "сортиовки заранее отсортированного массива, в обратном порядке слиянием ");
    free(arr);

    n = 20000;
    arr = sorted_bigarr(n);
    time_manage(arr, n, reverse_buble_sort_positive_elements, "сортировки заранее отсортированного массива, в обратном порядке пузырьком ");
    free(arr);

    return 0;
}


