//
// Created by alexe on 16.12.2023.
//

#ifndef EX1_7_FUNCTIONS_H
#define EX1_7_FUNCTIONS_H

#endif //EX1_7_FUNCTIONS_H

int* test(int n);
void output (int* arr, int n);
int* bigarr(int n);
void merge_sort_positive_elements(int* arr, int n);
void reverse_merge_sort_positive_elements(int* arr, int n);
void buble_sort_positive_elements(int* arr, int n);
void reverse_buble_sort_positive_elements(int* arr, int n);
int* sorted_arr (int n);
int* sorted_bigarr (int n);
void time_manage (int* arr, int n, void (*sortcode)(int[], int), const char* sortchar);