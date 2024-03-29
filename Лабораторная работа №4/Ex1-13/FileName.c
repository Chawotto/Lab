#include <windows.h> 
#include <stdio.h>

void testmatrix(int arr[][100], int N, int M) {
    int test_array[][100] = {{1,2,3,4},{5,0,3,0},{9,9,3,9},{1,0,3,0}};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = test_array[i][j];
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

    void inputMatrix(int arr[][100], int N, int M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("arr[%d][%d]=", i, j);
                scanf("%d", &arr[i][j]);
            }
        }
    }

    void printMatrix(int arr[][100], int N, int M) {
        printf("A[N][M]=");
        printf("\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%4d", arr[i][j]);
            }
            printf("\n");
        }
    }

    int countRowsWithZero(int arr[][100], int N, int M) { //нулевой эл
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 0) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }

    int Last(int arr[][100], int N, int M) { //серия посл элементов
        int maxSeriesLength = 0;
        int lastColumn = -1;

        for (int j = 0; j < M; j++) {
            int seriesLength = 1;

            for (int i = 0; i < N - 1; i++) {
                if (arr[i][j] == arr[i + 1][j]) {
                    seriesLength++;
                }
                else {
                    if (seriesLength > maxSeriesLength) {
                        maxSeriesLength = seriesLength;
                        lastColumn = j;
                    }
                    seriesLength = 1;
                }
            }

            if (seriesLength > maxSeriesLength) {
                maxSeriesLength = seriesLength;
                lastColumn = j;
            }
        }

        return lastColumn;
    }

    int main() {
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        int choice;
        int N, M;
        printf("Введите размер матрицы NxM\n");
        printf("N=");
        scanf("%d", &N);
        printf("M=");
        scanf("%d", &M);

        int arr[100][100];

        printf("1) Ввод матрицы вручную\n2) Тестовая матрица\n");
        scanf("%d", &choice);
        switch(choice){
        case 1 :
                inputMatrix(arr, N, M);
                printMatrix(arr, N, M);
                break;
            
        case 2 :

            testmatrix(arr, N, M);

            break;
        default:
        
            printf("Неверное значение\n");

            break;
        }

       

        int rowsWithZero = countRowsWithZero(arr, N, M);
        printf("Количество строк, содержащих хотя бы один нулевой элемент: %d\n", rowsWithZero);

        int lastCol =Last(arr, N, M);
        printf("Номер последнего столбца, в котором находится самая длинная серия одинаковых элементов: %d\n", lastCol);

        return 0;
    }