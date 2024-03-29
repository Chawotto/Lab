//
// Created by alexe on 19.12.2023.
//

//
// Created by Morra . on 14.11.2023.
//

#include <stdio.h>

void output(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}

