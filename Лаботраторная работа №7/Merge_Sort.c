
// Функция для подсчета количества лишних пробелов в строке
int countExtraSpaces(const char* str) {
    int i = 0;
    int count = 0;
    int consecutiveSpaces = 0;
    int extraSpaces = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            consecutiveSpaces++;
        } else {
            if (consecutiveSpaces > 1) {
                extraSpaces += consecutiveSpaces - 1;
                count++;
            }
            consecutiveSpaces = 0;
        }
        i++;
    }

    return extraSpaces + count;
}

// Функция для слияния двух отсортированных массивов строк
void merge(char** arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создание временных массивов
    char* L[n1];
    char* R[n2];

    // Копирование данных во временные массивы
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в arr[left..right]
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        // Сравнение строк по наибольшему количеству лишних пробелов
        if (countExtraSpaces(L[i]) >= countExtraSpaces(R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов из L[], если они есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов из R[], если они есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Функция сортировки слиянием
void mergeSort(char** arr, int left, int right) {
    if (left < right) {
        // Нахождение среднего элемента
        int mid = left + (right - left) / 2;

        // Рекурсивная сортировка двух половинок
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Слияние двух отсортированных половинок
        merge(arr, left, mid, right);
    }
}