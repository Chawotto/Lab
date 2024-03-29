//
// Created by alexe on 17.12.2023.
//

void buble_sort(int* arr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void buble_sort_positive_elements(int* arr, int n) {
    int positiveArr[n];
    int positiveCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveArr[positiveCount] = arr[i];
            positiveCount++;
        }
    }

    buble_sort(positiveArr, positiveCount);

    int positiveIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] = positiveArr[positiveIndex];
            positiveIndex++;
        }
    }
}

void reverse_buble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void reverse_buble_sort_positive_elements(int* arr, int n) {
    int positiveArr[n];
    int positiveCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveArr[positiveCount] = arr[i];
            positiveCount++;
        }
    }

    reverse_buble_sort(positiveArr, positiveCount);

    int positiveIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] = positiveArr[positiveIndex];
            positiveIndex++;
        }
    }
}
