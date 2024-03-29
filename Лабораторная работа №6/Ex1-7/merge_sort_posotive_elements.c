//
// Created by alexe on 17.12.2023.
//

void merge(int* arr, int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int* arr, int n) {
    if (n <= 1) {
        return;
    }
    int mid;
    if (n % 2 == 0) {
        mid = n / 2;
    }
    else mid = (n + 1)/2;

    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);

    merge(arr, left, mid, right, n - mid);
}
void merge_sort_positive_elements(int* arr, int n) {

    int positiveArr[n];
    int positiveCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveArr[positiveCount] = arr[i];
            positiveCount++;
        }
    }

    merge_sort(positiveArr, positiveCount);

    int positiveIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] = positiveArr[positiveIndex];
            positiveIndex++;
        }
    }
}

void reverse_merge(int* arr, int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] >= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void reverse_merge_sort(int* arr, int n) {
    if (n <= 1) {
        return;
    }
    int mid;
    if (n % 2 == 0) {
        mid = n / 2;
    }
    else mid = (n + 1)/2;

    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    reverse_merge_sort(right, n - mid);
    reverse_merge_sort(left, mid);

    reverse_merge(arr, left, mid, right, n - mid);
}
void reverse_merge_sort_positive_elements(int* arr, int n) {

    int positiveArr[n];
    int positiveCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveArr[positiveCount] = arr[i];
            positiveCount++;
        }
    }

    reverse_merge_sort(positiveArr, positiveCount);

    int positiveIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] = positiveArr[positiveIndex];
            positiveIndex++;
        }
    }
}



