//1. Найти в матрице первую строку, все элементы которой положительны, и сумму всех элементов этой строки.Уменьшить все элементы матрицы на эту сумму.


#include <windows.h> 
#include <stdio.h>

void testmatrix(int arr[][100], int N, int M) {
    int test_array[][100] = { {-1,2,3,4},{5,0,3,0},{9,9,3,9},{-1,0,3,0} };
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

void findPositiveRow(int arr[][100], int N, int M) {
    int sum = 0;
    int positiveRow = -1;
    for (int i = 0; i < N; i++) {
        int allPositive = 1;
        for (int j = 0; j < M; j++) {
            if (arr[i][j] < 0) {
                allPositive = 0;
                break;
            }
        }
        if (allPositive) {
            positiveRow = i;
            break;
        }
    }

    if (positiveRow == -1) {
        printf("Нету строк с полностью неотрицательными значениями\n");
        return;
    }

    for (int j = 0; j < M; j++) {
        sum += arr[positiveRow][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] -= sum;
        }
    }

    printf("Положительная строка %d.\n", positiveRow);
    printf("Сумма элементов этой строки: %d.\n", sum);
}

int editedmatrix(int arr[][100], int N, int M) {
    printf("Измененная матрица: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int s = 0, el = 0, p = 0;
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
    printf("\n");


    switch (choice) {
    case 1:
        inputMatrix(arr, N, M);
        printMatrix(arr, N, M);
        break;

    case 2:

        testmatrix(arr, N, M);

        break;
    default:

        printf("Неверное значение\n");

        break;
    }
    findPositiveRow(arr, N, M);
    printf(editedmatrix(arr, N, M));


    return 0;
}