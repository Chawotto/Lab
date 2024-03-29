//
// Created by alexe on 16.12.2023.
//

#include <stdlib.h>

int* test(int n) {
    int *testarr = (int *) malloc ((n + 1) * sizeof(int));
    int test_array1[10] = {12, -2, 7, -4, 5, 6, 3, -8, 9, 24};
    for (int i = 0; i < n; i++) {
        testarr[i] = test_array1[i];
    }
    return testarr;
}

int* sorted_arr (int n){
    int *testarr = (int *) malloc((n + 1) * sizeof(int));
    int test_array1[10] = {3, -2, 5, -4, 6, 7, 9, -8, 12, 24};
    for (int i = 0; i < n; i++) {
        testarr[i] = test_array1[i];
    }
    return testarr;
}
