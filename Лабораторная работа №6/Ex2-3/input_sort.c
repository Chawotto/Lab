//
// Created by alexe on 19.12.2023.
//

//3. В прямоугольной матрице размером выполнить сортировку строк по убыванию
//количества четных элементов методом вставок.

#include <stdlib.h>
#include <stdio.h>


int* even_count (int** array, int rows, int cols){

    int* even = (int*)malloc(rows * sizeof(int));
    int count = 0;

    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++ ){
            if(array[i][j] % 2 == 0){
                count++;
            }
        }
        even[i] = count;
        count = 0;
    }
    return even;
}







int** insert_sort (int** array, int rows, int cols, int* even){
    for (int i = 1; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            int k = i;
            while (k >= 0 && even[k - 1] > even[k]){
                int tmp [cols];
                for(int d = 0; d < cols; d++){
                    tmp[d] = array[k - 1][j];
                }
                array[k - 1] = array[k];

                for(int d = 0; d < cols; d++){
                    array[k][j] = tmp[d];
                }

                k -= 1;
                printf("salam");
            }
        }
    }

    return array;
}
//эталон
// 6  3  1  5  7
// 1  6  5  9  8
// 2  4  3  6  3
// 4  2  6  1  4

//void insert_sort(int A[], int N)
//{
//    for(int i = 1; i < N; ++i)
//    {
//        int k = i;
//        while (k > 0 and A[k-1] > A[k])
//        {
//            int tmp = A[k-1];
//            A[k-1] = A[k];
//            A[k] = tmp;
//            k -= 1;
//        }
//    }
//}