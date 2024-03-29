//
// Created by ASUS on 21.12.2023.
//
#include <time.h>
#include <stdio.h>

void time_manage (int* arr, int n, void (*sortcode)(int[], int), const char *sortname){
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortcode(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Время %s: %f секунд\n", sortname, cpu_time_used);
}